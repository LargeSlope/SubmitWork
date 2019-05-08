#include "TileMng.h"
#define CINPUT
#include "lib/LsLib.h"
#undef CINPUT
#include "lib.h"
#include "GameSetting.h"

//描画位置（定数でないため，ここで定義しております）
#define DRAW_TILE_POINT_X	(BOARD_SPOINT_X + (i % BOARD_SIZE_X) * TILE_PXSIZE_X)
#define DRAW_TILE_POINT_Y	(BOARD_SPOINT_Y + (i / BOARD_SIZE_X) * TILE_PXSIZE_Y)

using namespace input;

//タイル実体
Tile TileMng::tile[BOARD_SIZE_NUM] = {};

//スコア
int TileMng::score = 0;

//クイックモード
bool TileMng::quick = true;

//タイルの初期化
void TileMng::init() {

	//グラフ読み込み
	Tile::loadGraph(TILE_GRAPH_NAME);

	//スコアのリセット
	score = 0;

	//タイルの値セット
	for (int i = 0; i < BOARD_SIZE_NUM; i++) {

		tile[i].setValue(GetRand(TILE_GRAPH_XNUM - 1));
	}
}

//描画(ドラッグ以外)
int TileMng::_draw() {

	int drag_index = getDragIndex();

	for (int i = 0; i < BOARD_SIZE_NUM; i++) {

		if (i == drag_index && drag()) continue;

		tile[i].draw(DRAW_TILE_POINT_X, DRAW_TILE_POINT_Y);
	}

	return drag_index;
}

//描画(ドラッグ込み)
void TileMng::draw() {

	//ドラッグ中のインデックス
	int drag_index = _draw();

	//ドラッグ中のタイルを描画
	if (drag()) tile[drag_index].draw(Input::mouse.point.x - 24, Input::mouse.point.y - 24);
}

//更新
int TileMng::update() {

	//ドラッグによる交換
	exchange();

	//マッチ3を実行する
	match3();

	//消去予約タイルを消去する
	vanish();

	//タイルの落下
	fall();

	//タイルの補填
	fill();

	//スコアを返却
	return score;
}

//ドラッグによる交換
void TileMng::exchange() {
	if (!fdrag()) return;	//範囲内でのドラッグ　かつ　ドラッグが完了したこと　が条件
	int sindex_x = ctoi(Input::mouse.s_point.x, HORIZONTAL),
		sindex_y = ctoi(Input::mouse.s_point.y, VARTICAL);
	int eindex_x = ctoi(Input::mouse.e_point.x, HORIZONTAL),
		eindex_y = ctoi(Input::mouse.e_point.y, VARTICAL);

	//隣同士以外の交換を禁止する
	if (ABS((sindex_x + sindex_y * BOARD_SIZE_X) - (eindex_x + eindex_y * BOARD_SIZE_X)) != 1 &&
		ABS((sindex_x + sindex_y * BOARD_SIZE_X) - (eindex_x + eindex_y * BOARD_SIZE_X)) != 10  ||
		(sindex_x == 0 && eindex_x == 9) || (sindex_x == 9 && eindex_x == 0)) return;

	Tile::exchange(tile[sindex_x + sindex_y * BOARD_SIZE_X], tile[eindex_x + eindex_y * BOARD_SIZE_X]);
}

//消去
void TileMng::vanish() {

	for (int i = 0; i < BOARD_SIZE_NUM; i++) {

		//通常モード時
		if (tile[i].vanish && !quick) {

			//アニメーション実行
			if (tile[i].advanceVAnim()) {

				//アニメーション完了後，消去予約フラグをOFFにする
				tile[i].vanish = false;

				//スコアの加算
				score += 10;
			}
		}
		//クイックモード時
		else if (tile[i].vanish) {

			tile[i].quickVAnim();
			tile[i].vanish = false;
		}
	}
}

//マッチ3用消去済みチェック(true:消去中または消去済みのタイルが存在)
bool TileMng::checkVanish(int index1, int index2, int index3) {

	if (tile[index1].getVState(VANISHED) ||
		tile[index2].getVState(VANISHED) ||
		tile[index3].getVState(VANISHED) ||
		tile[index1].getVState(VANISHING) ||
		tile[index2].getVState(VANISHING) ||
		tile[index3].getVState(VANISHING)) return true;
	return false;
}

//1行消去
void TileMng::vanishLine(int index) {

	//行番号取得
	int lnum = index / BOARD_SIZE_X;

	//一括消去
	for (int i = 0; i < BOARD_SIZE_X; i++) {

		tile[lnum * VARTICAL + i].vanish = true;
	}
}

//1列消去
void TileMng::vanishRow(int index) {

	//列番号取得
	int rnum = index % BOARD_SIZE_X;

	//一括消去
	for (int i = BOARD_SIZE_Y / 2; i < BOARD_SIZE_Y; i++) {

		tile[rnum + VARTICAL * i].vanish = true;
	}
}

//範囲消去
void TileMng::vanishSq(int index) {

	//はみ出し防止(indexの位置が端に存在するときのフラグ)
	bool top = !(index / BOARD_SIZE_X),
		right = !(index % BOARD_SIZE_X - 9),
		bottom = !(index / BOARD_SIZE_X - 19),
		left = !(index % BOARD_SIZE_X);

	if (!top && !left)		tile[index + (-11)].vanish = true;
	if (!top)				tile[index + (-10)].vanish = true;
	if (!top && !right)		tile[index + (-9)].vanish = true;
	if (!left)				tile[index + (-1)].vanish = true;
	if (!right)				tile[index + (+1)].vanish = true;
	if (!bottom && !left)	tile[index + (+9)].vanish = true;
	if (!bottom)			tile[index + (+10)].vanish = true;
	if (!bottom && !right)	tile[index + (+11)].vanish = true;
}

//特殊タイルの消去
void TileMng::vanishSpecial() {
	for (int i = BOARD_SIZE_NUM / 2; i < BOARD_SIZE_NUM; i++) {
		if (!tile[i].vanish) continue;
		switch (tile[i].getValueType()) {
		case 1: vanishLine(i); break;
		case 2: vanishRow(i); break;
		case 3: vanishSq(i); break;
		default: break;
		}
	}
}

//マッチ3(方向指定)
void TileMng::_match3(int index, int dir) {

	int color0 = tile[index + dir * 0].getValueColor(),
		color1 = tile[index + dir * 1].getValueColor(),
		color2 = tile[index + dir * 2].getValueColor();

	//消去中のタイルとはマッチングしない
	if (checkVanish(index + dir * 0, index + dir * 1, index + dir * 2)) return;

	//全ての色が一致時，vanishフラグをtrueにする
	if ((color0 == color1) && (color1 == color2)) {

		tile[index + dir * 0].vanish = true;
		tile[index + dir * 1].vanish = true;
		tile[index + dir * 2].vanish = true;
	}
}

//マッチ3
void TileMng::match3() {

	//マッチング(下半領域)
	for (int i = BOARD_SIZE_NUM / 2; i < BOARD_SIZE_NUM - 2; i++) {

		if ((i / BOARD_SIZE_X) < (BOARD_SIZE_Y - 2)) _match3(i, VARTICAL);	//縦マッチング
		if ((i % BOARD_SIZE_X) < (BOARD_SIZE_X - 2)) _match3(i, HORIZONTAL); //横マッチング
	}

	//特殊タイルを消去
	vanishSpecial();
}

//落下による交換
void TileMng::fexchange(int index1, int count) {

	int index2 = index1 + (count * VARTICAL);
	if (index2 >= BOARD_SIZE_NUM) return; //例外処理（out of range）

	tile[index1].resetFallFrame();
	tile[index2].resetFallFrame();
	Tile::exchange(tile[index1], tile[index2]);
}

//落下
void TileMng::fall() {

	int count = 0; //空タイルカウンタ

	for (int i = 0; i < BOARD_SIZE_NUM; i++) {

		//逆縦探索
		int index = reverse(i);

		//空タイルならばカウントアップ
		if (tile[index].getVState()) { count++;
		
			//最上部が空タイルならばカウンタリセット
			if (index < VARTICAL) count = 0; continue;
		}

		//落下完了時に，タイルを交換
		if (tile[index].getFFinished(count)) fexchange(index, count);

		//タイルを落下させるアニメーション
		else if(!quick) tile[index].advanceFAnim(count);

		//クイック落下
		else if(count) fexchange(index, count);

		//最上部の時はカウンタをリセットする
		if (index < VARTICAL) count = 0;
	}
}

//安定状態を取得(戻り値true:安定 false:不安定)
bool TileMng::stable() {

	bool result = false;

	match3();

	for (int i = 0; i < BOARD_SIZE_NUM; i++) {

		result |= tile[i].vanish | (bool)tile[i].getFState();
	}
	return !result;
}

//補填
void TileMng::fill() {

	for (int i = 0; i < BOARD_SIZE_NUM / 2; i++) {

		if (tile[i].getVState()) {

			tile[i].setValue(GetRand(TILE_GRAPH_XNUM - 1));
			tile[i].resetVAnim();
		}
	}
}