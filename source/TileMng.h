#pragma once
#include "Tiles.h"
#include "GameSetting.h"

//タイルオブジェクト管理クラス
class TileMng {

	static Tile tile[BOARD_SIZE_NUM];

	static int score;

	//描画 (戻り値：ドラッグ中のタイルのindex)
	static int _draw();

	//ドラッグによる交換
	static void exchange();

	//マッチ3(方向指定)
	static void _match3(int index, int dir);

	//マッチ3
	static void match3();

	//マッチ3用消去済みチェック
	static bool checkVanish(int index1, int index2, int index3);

	//1行消去
	static void vanishLine(int index);

	//1列消去
	static void vanishRow(int index);

	//範囲消去
	static void vanishSq(int index);

	//特殊タイルの消去
	static void vanishSpecial();

	//落下による交換
	static void fexchange(int index1, int count);

	//消去
	static void vanish();

	//落下
	static void fall();

	//補填
	static void fill();

public:

	//クイックモード
	static bool quick;

	//安定状態を取得(戻り値true:安定 false:不安定)
	static bool stable();

	//タイルの初期化
	static void init();

	//更新
	static int update();

	//描画
	static void draw();
};