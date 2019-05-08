#include "GameManager.h"
#include "Window.h"
#define WINFUNC
#define CINPUT
#include "lib/LsLib.h"
#undef CINPUT
#undef WINFUNC

using namespace input;

//盤面管理
Board GameManager::board;

//スコア
int GameManager::score = 0;

//入力可能状態
bool GameManager::available = true;

//リザルト画面
Result GameManager::result;

//タイトル画面
Title GameManager::title;

//ハイスコア
int GameManager::hscore = 0;


//初期化処理 (戻り値 0：正常 1：異常終了)
int GameManager::gInit() {

	TileMng::init();

	hscore = result.loadHighScore();
	result.loadBackground();

	return 0;
}

//タイトル画面の更新
void GameManager::UpdateTitle() {

	title.update();
	title.draw();
}

//盤面安定化処理（初期化）
void GameManager::StableBoard() {

	//安定するまでクイックマッチ3を行う
	if (TileMng::quick) {

		//安定化処理
		while (!TileMng::stable()) {

			TileMng::update();
		}
		TileMng::quick = false;
	}
}

//ゲームメイン画面の更新
void GameManager::UpdateGame() {

	//test
	int test = 0;

	//スコア及びタイル管理状態の更新
	int score = TileMng::update();

	//盤面安定化(クイック時のみ)
	StableBoard();

	//背景の描画
	board.drawBackground();
	
	//タイルの描画
	TileMng::draw();

	//前景の描画
	board.drawForeGround(score, hscore);


	//盤面の更新
	if (board.update()) {

		available = false; //TimeUP時，操作禁止
		board.drawTimeUP(); //"TimeUP"を表示する

		//安定化状態にあるとき
		if ( TileMng::stable() ) {

			Input::reset(); //入力値をリセット

			//3秒後，次のレベルに移動
			if (board.fupdate()) {

				//スコアを挿入(ハイスコアも取得)
				hscore = result.insert(score);

				board.reset(); //制限時間と3秒カウンタをリセット
				window::nextWindow(); //次のレベル
			}
		}
	}
}

//リザルト画面の更新
void GameManager::UpdateResult() {

	result.update();
	result.draw();

	if (window::getWindowNum() != 2) {

		//ボードのリセット
		board.reset();

		//タイルマネージャのリセット
		TileMng::init();

		//クイックモードを有効にする
		TileMng::quick = true;

		//盤面を操作可能にする
		available = true;
	}
}

//レベル切り替え処理
void GameManager::switchLevel() {

	switch (window::getWindowNum()) {
	case TITLE: UpdateTitle(); break;
	case GMAIN: UpdateGame(); break;
	case RESULT: UpdateResult(); break;
	default:break;
	}
}

//メイン処理
void GameManager::gMain() {

	//ウィンドウを0番目(TITLE)に設定
	window::setWindowNum( TITLE );

	//タイトル画面の初期化
	title.loadGraph();

	//盤面の初期化
	board = Board();

	//メインループ（フレーム更新）
	while (Loop(ALL)) {

		//マウスクリック終了時，ウィンドウを操作可能にする
		if (Input::mouse.detach[LEFT]) window::Available = true;

		//マウスポインタとキーボードの更新
		if(available) Input::update(MOUSE & KEYBD);

		//キーボードの更新
		else Input::update(KEYBD);

		//ウィンドウ番号ごとにレベルを切り替え
		switchLevel();

		//Escを押したときにゲームを終了させる
		if (Input::key.value[KEY_INPUT_ESCAPE] == 1) break;
	}
}