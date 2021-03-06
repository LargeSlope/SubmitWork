#include "lib.h"
#define CINPUT
#include "lib/LsLib.h"
#undef CINPUT
#include "GameSetting.h"

using namespace input;

//ドラッグ中のインデックス取得
int getDragIndex() {

	int index_x = (Input::mouse.s_point.x - BOARD_SPOINT_X) / TILE_PXSIZE_X;
	int index_y = (Input::mouse.s_point.y - BOARD_SPOINT_Y) / TILE_PXSIZE_Y;
	return (index_x + index_y * BOARD_SIZE_X);
}

//ドラッグ判定
bool drag() {

	//ドラッグ範囲内にドラッグ開始ポイントが存在すること
	bool result1 = BOARD_AREA < Input::mouse.s_point;

	//ドラッグ中であること
	bool result2 = Input::mouse.push[0] > 0;

	return result1 && result2;
}

//ドラッグ完了判定
bool fdrag() {

	//ドラッグ範囲内にドラッグ開始・終了ポイントが存在すること
	bool result1 = BOARD_AREA < Input::mouse.s_point;
	bool result2 = BOARD_AREA < Input::mouse.e_point;

	//ドラッグ操作が終了したこと
	bool result3 = Input::mouse.detach[LEFT];

	return (result1 && result2 && result3);
}

/*リバース関数について*/
//下図のように，下から上に向かって探索するよう，indexの定義を変更します．
//右側から，1列探索し終えたら，次(左)の列を探索します．
//〇〇〇〇〇〇〇↑↑↑
//〇〇〇〇〇〇〇↑↑↑
//〇〇〇〇〇〇〇↑↑↑
//〇〇〇〇〇〇〇↑↑↑
//〇〇〇〇〇〇〇↑↑↑
//〇〇〇〇〇〇〇↑↑↑
//〇〇〇〇〇〇〇↑↑↑
//〇〇〇〇〇〇〇↑↑↑
//〇〇〇〇〇〇〇↑↑↑
//〇〇〇〇〇〇…�B�A�@


//indexのリバース関数
int reverse(int index) {

	int index_x = BOARD_SIZE_X - (index / BOARD_SIZE_Y) - 1;
	int index_y = BOARD_SIZE_Y - (index % BOARD_SIZE_Y) - 1;

	return (index_x + index_y * BOARD_SIZE_X);
}

//coordinate to index
int ctoi(int coordinate, int dir) {

	switch (dir) {
	case VARTICAL:   return ((coordinate - BOARD_SPOINT_Y) / TILE_PXSIZE_Y);
	case HORIZONTAL: return ((coordinate - BOARD_SPOINT_X) / TILE_PXSIZE_X);
	default:break;
	}
	return -1;
}

//yのindexが0であるかないかを確認する関数
bool check_yindex_min(int index) {

	return index < BOARD_SIZE_X;
}