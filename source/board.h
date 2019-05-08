#pragma once

//盤面管理クラス
class Board {

	//グラフィックハンドル([0]:背景 [1]:前景 [2]:TimeUP)
	int graph[3] = {};

	//制限時間
	int time = 0;

	//フリーズタイム
	int ftime = 0;

public:

	//グラフィック読み込み
	Board();

	//制限時間のリセット
	void reset();

	//盤面の更新(制限時間 false:未完了 true:完了)
	bool update();

	//フリーズタイムのアップデート
	bool fupdate();

	//背景の描画
	void drawBackground();

	//前景の描画
	void drawForeGround(int score, int hscore);

	//TimeUPを描画
	void drawTimeUP();
};