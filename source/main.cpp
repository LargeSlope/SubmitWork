#define WINFUNC
#include "lib/LsLib.h"
#include "GameManager.h"

//エントリポイント
int main() {

	//DxLibの初期化
	Init;

	//ゲームマネージャ初期化
	GameManager::gInit();

	//ゲームマネージャ更新処理
	GameManager::gMain();

	//DxLib終了処理
	DxLib::DxLib_End();

	//ゲーム終了
	return 0;
}