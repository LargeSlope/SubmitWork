#pragma once


//タイトル画面
class Title {

	int graph = 0;

	int select = 0;

public:
	//背景を読み込む
	void loadGraph();

	//更新
	void update();

	//描画
	void draw();
};