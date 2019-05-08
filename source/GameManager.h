#pragma once
#include "TileMng.h"
#include "board.h"
#include "Result.h"
#include "Title.h"

#define TITLE (0)
#define GMAIN (1)
#define RESULT (2)

//ゲームマネージャ
class GameManager {

	//盤面管理
	static Board board;

	//リザルト画面
	static Result result;

	//タイトル画面
	static Title title;

	//スコア
	static int score;

	//ハイスコア
	static int hscore;

	//入力可能状態
	static bool available;

	//盤面安定化処理
	static void StableBoard();

	//タイトル画面の更新
	static void UpdateTitle();

	//ゲームメイン画面の更新
	static void UpdateGame();

	//リザルト画面の更新
	static void UpdateResult();

	//レベル切り替え処理
	static void switchLevel();

public:

	//初期化処理 (戻り値 0：正常 1：異常終了)
	static int gInit();

	//メイン処理
	static void gMain();
};