#include "Result.h"
#define CINPUT
#include "lib/LsLib.h"
#undef CINPUT
#include "GameSetting.h"
#include "Window.h"
#include <string>
#include <fstream>
#include <algorithm>
#include "DxLib.h"

using namespace input;
using namespace std;


//ハイスコア履歴を読み込む
int Result::loadHighScore() {

	//バッファ
	char score_buff[10] = "";

	//ファイルオープン
	int fscore = FileRead_open(RESULT_HISCORE);

	//ハイスコアを初期化
	hiscore = vector<int>(HISCORE_NUM);

	//ファイルの読み込み
	for (int i = 0; i < HISCORE_NUM; i++) {

		//ファイルの終端の時，break
		if (FileRead_eof(fscore)) break;

		//ファイルを1行読み出す
		FileRead_gets(score_buff, 10, fscore);

		//ハイスコアを格納
		hiscore[i] = atoi(score_buff);
	}
	//ファイルを閉じる
	FileRead_close(fscore);

	return hiscore[0];
}

//リザルト画面の背景を読み込む
void Result::loadBackground() {

	graph = LoadGraph(RESULT_GRAPH_NAME);
}

//メニュー
void Result::update() {

	//メニューセレクト
	if (Input::key.value[KEY_INPUT_UP] == 1)   select = --select % SELECT_MAX;
	if (Input::key.value[KEY_INPUT_DOWN] == 1) select = ++select % SELECT_MAX;

	//決定
	if (Input::key.value[KEY_INPUT_RETURN] == 1) {

		//ハイスコアを保存
		saveHighScore();

		//タイトル画面
		if (select) window::setWindowNum(1);
		else window::nextWindow();
	}
}

//描画する
void Result::draw() {

	int str_width[2] = {

		GetDrawStringWidth("TITLE", 6),
		GetDrawStringWidth("CONTINUE", 8)
	};

	//背景
	DrawGraph(0, 0, graph, TRUE);

	//ハイスコア
	for (int i = 0; i < HISCORE_NUM; i++) {

		if (i == score_index) DrawBox(304, 252 + 25 * i, 550, 274 + 25 * i, white, FALSE);
		DrawFormatString(304, 254 + 25 * i, white, "%3d.", i + 1);
		DrawFormatString(454, 254 + 25 * i, white, "%5d", hiscore[i]);
	}

	//メニュー
	DrawBox(340, 515 + ABS(select) * 25, 476, 540 + ABS(select) * 25, sky, TRUE);

	DxLib::DrawFormatString((WINDOW_SIZE_X / 2) - (str_width[0] / 2), 520, select ? white : gray15, "TITLE");
	DxLib::DrawFormatString((WINDOW_SIZE_X / 2) - (str_width[1] / 2), 544, select ? gray15 : white, "CONTINUE");
}

//結果を保存
void Result::saveHighScore() {

	ofstream ofs;

	//スコアファイルをオープン
	ofs.open(RESULT_HISCORE, ios::out);

	//数値データを文字列に変換
	for (int i = 0; i < HISCORE_NUM; i++) {

		ofs << to_string(hiscore[i]).c_str() << endl;
	}

	//ファイルクローズ
	ofs.close();
}

//ハイスコアを挿入する
int Result::insert(int score) {

	//スコアを挿入
	hiscore.push_back(score);

	//降順ソート
	sort(hiscore.begin(), hiscore.end(), std::greater<int>());

	//リサイズ
	hiscore.resize(HISCORE_NUM);

	//ハイスコアの位置を求める
	for (int i = 0; i < HISCORE_NUM; i++) {

		if (hiscore[i] == score) score_index = i;
	}

	return hiscore[0];
}