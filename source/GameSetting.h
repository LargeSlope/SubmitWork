#pragma once
//ゲーム内容に関するセッティング項目です

/* [lslib\higher\winfunc.h]
#define WINDOW_SIZE_X	(816)	//ウィンドウ横サイズ[px]
#define WINDOW_SIZE_Y	(624)	//ウィンドウ縦サイズ[px]
*/

#define TILE_GRAPH_NUM (25)	//タイル画像の総分割数です("Resource\Image\tiles.png")
#define TILE_GRAPH_XNUM (5)	//タイル画像の横分割数(色数)
#define TILE_GRAPH_YNUM (5)	//タイル画像の縦分割数(アニメーションフレーム数)

#define TILE_PXSIZE_X (48)	//タイル分割済み画像の1枚当たりの横サイズ[px]
#define TILE_PXSIZE_Y (48)	//タイル分割済み画像の1枚当たりの縦サイズ[px]

#define BOARD_SIZE_NUM (200)	//10[tiles] * 20[tiles]
#define BOARD_SIZE_X (10)	//10[tiles]
#define BOARD_SIZE_Y (20)	//上半領域 + 下半領域 = 20[tile]

#define BOARD_SPOINT_X (168)	//(816-(48*10))/2
#define BOARD_SPOINT_Y (-408)	//(624-(48*10))/2 -(48*10)

#define BOARD_AREA point2<int>(168, 72, 648, 552)	//マウスで扱える範囲
#define BOARD_AREA2 point2<int>(168, 72, 600, 504)	//マウスで扱える範囲

#define BOARD_DRAW_POINT_X BOARD_SPOINT_X + (i % BOARD_SIZE_X) * TILE_PXSIZE_X
#define BOARD_DRAW_POINT_Y BOARD_SPOINT_Y + (i / BOARD_SIZE_X) * TILE_PXSIZE_Y

#define TILE_GRAPH_NAME "Resource/Image/tiles.png"
#define ARROW_GRAPH_NAME "Resource/Image/arrow.png"
#define BOARD_GRAPH_NAME "Resource/Image/board.png"
#define BOARD_GRAPH_NAME2 "Resource/Image/board2.png"
#define BOARD_GRAPH_NAME3 "Resource/Image/timeup.png"
#define RESULT_GRAPH_NAME "Resource/Image/result.png"
#define TITLE_GRAPH_NAME "Resource/Image/menu.png"

#define RESULT_HISCORE "score/score.txt"


#define VARTICAL	BOARD_SIZE_X	//マッチング方向(縦)
#define HORIZONTAL	(1)	//マッチング方向(横)

#define ANIM_DIM	2	//アニメーションは2種類存在
#define VANISH	0	//消去次元
#define FALL	1	//落下次元

#define QUICK true	//クイックモードを選択

#define VANISHING true
#define VANISHED false

#define ON true
#define OFF false

#define WINNUM (3)

#define TIME_MAX (30 * 60)	//時間制限30[s]*60FPS
#define FTIME_MAX (3 * 60) //3[s]*60FPS
