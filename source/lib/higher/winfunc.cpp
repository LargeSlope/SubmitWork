/*///////////////////////////////////////////////////////////////////////////////////////////////////
*【ウィンドウ標準実装】																				*
*	作成日：2019/1/26																				*
*	更新日：2019/1/26																				*
*	バージョン：1.0.0																				*
///////////////////////////////////////////////////////////////////////////////////////////////////*/
#include "winfunc.h"
#include "DxLib.h"

//ウィンドウ初期化関数（DXライブラリ依存）
int Winit() {

	SetUseDirectDrawDeviceIndex(1);

	if (SetGraphMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, 16) != DX_CHANGESCREEN_OK) return 1;

	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK) return 2;

	if (SetBackgroundColor((WINDOW_COLOR & 0x00FF0000) >> 16, (WINDOW_COLOR & 0x0000FF00) >> 8, (WINDOW_COLOR & 0x000000FF))) return 3;

	if (DxLib_Init()) return 4; //DxLib初期化

	if (SetDrawScreen(DX_SCREEN_BACK)) return 5; //BackGround描画

	return 0;
}

//ウィンドウ更新処理（DXライブラリ依存）
int Wupdate(unsigned char update_flag) {

	//(裏画面を表画面に反映, メッセージ処理, 画面クリア)

	return (
		(!(update_flag & 0x01) ? (ScreenFlip() == 0) : 1) &&
		(!(update_flag & 0x02) ? (ProcessMessage() == 0) : 1) &&
		(!(update_flag & 0x04) ? (ClearDrawScreen() == 0) : 1)
		);
}

//プロセス終了
void End() {

	DxLib_End(); // DXライブラリ終了処理
}