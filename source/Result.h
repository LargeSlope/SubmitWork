#pragma once
/* リザルト画面を管理するクラスです */
#include <vector>

#define HISCORE_NUM (10)
#define SELECT_MAX (2)

using namespace std;

//リザルトクラス
class Result {

	int graph = 0; //グラフィックハンドル

	vector<int> hiscore; //High Score

	int select = 0; //メニューのセレクト番号(0:TITLE 非0:CONTINUE)

	int score_index = 0; //今回のスコア順位

public:

	//ハイスコア履歴を読み込む
	int loadHighScore();

	//リザルト画面の背景を読み込む
	void loadBackground();

	//結果を保存
	void saveHighScore();

	//メニュー
	void update();

	//ハイスコアを挿入する
	int insert(int score);

	//描画する
	void draw();
};