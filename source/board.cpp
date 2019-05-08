#include "board.h"
#include "DxLib.h"
#include "GameSetting.h"
#include "lib/LsLib.h"

//グラフィック読み込み
Board::Board() {

	reset(); //制限時間のリセット
	graph[0] = LoadGraph(BOARD_GRAPH_NAME);  //背景
	graph[1] = LoadGraph(BOARD_GRAPH_NAME2); //前景
	graph[2] = LoadGraph(BOARD_GRAPH_NAME3); //TimeUP

	//フォントの種類を設定
	ChangeFont("メイリオ");

	//フォントサイズの指定
	SetFontSize(20);
}

//制限時間のリセット
void Board::reset() {

	time = 0;
	ftime = 0;
}

//盤面の更新(制限時間 false:未完了 true:完了)
bool Board::update() {

	if (time < TIME_MAX) time++;
	else return true;
	return false;
}

//フリーズタイムのアップデート
bool Board::fupdate() {

	if (ftime < FTIME_MAX) ftime++;
	else return true;
	return false;
}

//背景の描画
void Board::drawBackground() {

	DrawGraph(0, 0, graph[0], TRUE);
}

//前景の描画
void Board::drawForeGround(int score, int hscore) {

	//前景
	DrawGraph(0, 0, graph[1], TRUE);

	//制限時間の描画
	DrawBox(681, 186, 781, 206, white, FALSE);
	DrawBox(681, 186, 781 - (int)(100 * ((double)time / TIME_MAX)), 206, white, TRUE);
	DrawFormatString(735, 231, white, "%d", 30 - time / 60);

	//スコアの描画
	DrawFormatString(53, 138, white, "%d", score);

	//ハイスコアの描画
	DrawFormatString(53, 257, white, "%d", hscore);
}

//TimeUPを描画
void Board::drawTimeUP() {

	DrawGraph(0, 0, graph[2], TRUE);
}