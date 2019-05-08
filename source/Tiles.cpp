#include "Tiles.h"
#include "GameSetting.h"
#include "DxLib.h"

//グラフィックハンドル(DXLIB依存)
int Tile::ghandle[25] = { 0 };
//グラフィックハンドル（アローイメージ）
int Tile::ahandle[3] = { 0 };

//グラフィックを読み込む(DXLIB依存)
void Tile::loadGraph(const char *fileName) {

	//グラフィック読み込み関数(DXLIB)
	LoadDivGraph(
		fileName,
		TILE_GRAPH_NUM,
		TILE_GRAPH_XNUM, TILE_GRAPH_YNUM,
		TILE_PXSIZE_X, TILE_PXSIZE_Y,
		ghandle);

	//アローイメージの読み込み
	LoadDivGraph(ARROW_GRAPH_NAME, 3, 3, 1, 48, 48, ahandle);
}

//タイルの交換
void Tile::exchange(Tile &a, Tile &b) {

	Tile buff = a;
	a = b, b = buff;
}

//初期化
void Tile::setValue(const unsigned char Value) {

	int rand = GetRand(100);
	value = Value;
	vanish_frame = 0;
	fall_frame = 0;
	vanish = false;

	if (rand < 97) {
		value += 0;	//通常(97%)
	}
	else if (rand < 98) {
		value += 5;	//横(1%)
	}
	else if (rand < 99) {
		value += 10;//縦(1%)
	}
	else {
		value += 15;//範囲(1%)
	}
}

//値取得(0～4)
int  Tile::getValueColor() {

	return (int)value % TILE_GRAPH_XNUM;
}

//タイプ取得(0:定常 1:横 2:縦 3:範囲)
int  Tile::getValueType() {

	return (int)value / TILE_GRAPH_XNUM;
}

//消去の時間を進める(true:完了　false:未完了)
bool Tile::advanceVAnim() {

	if (vanish_frame < TILE_GRAPH_YNUM * 6) {

		vanish_frame++;
		return false;
	}
	else return true;
}

//クイック消去
void Tile::quickVAnim() {

	vanish_frame = TILE_GRAPH_YNUM * 6;
}

//消去時間をリセットする
void Tile::resetVAnim() {

	vanish_frame = 0;
}

//消去時間を取得する
int Tile::getVFrame() {

	return vanish_frame;
}

//消去状態を取得する(引数false:消去済みなら1，true:消去中なら1)
int Tile::getVState(bool type) {

	if ((vanish_frame >= TILE_GRAPH_YNUM * 6) && type == false) return 1;
	else if ((0 < vanish_frame) && (vanish_frame < TILE_GRAPH_YNUM * 6) && type == true) return 1;
	return 0;
}

//落下時間を進める
void Tile::advanceFAnim(int count) {

	if (fall_frame < count * 12) fall_frame++;
}

//落下時間をリセットする
void Tile::resetFallFrame() {

	fall_frame = 0;
}

//落下状態の取得
int Tile::getFState() {

	return fall_frame;
}

//落下完了状態を取得する(true:完了 false:未完了)
bool Tile::getFFinished(int count) {

	return (fall_frame >= count * 12) && count;
}

//描画(DXLIB依存)
void Tile::draw(const int& xPos, const int& yPos) {

	//グラフィック番号
	int graph_num = (value % TILE_GRAPH_XNUM) + (vanish_frame / TILE_GRAPH_XNUM) * TILE_GRAPH_XNUM;

	//例外処理
	if (graph_num < 0 || 24 < graph_num) return;

	//描画関数(DXLIB)
	DrawGraph(xPos, yPos + fall_frame * 4, ghandle[graph_num], TRUE);

	//タイプの表現
	if (getValueType()) DrawGraph(xPos, yPos + fall_frame * 4, ahandle[getValueType() - 1], TRUE);

	//test
	//DrawFormatString(xPos, yPos, 0x00, "%d", fall_frame);
}