#include "Title.h"
#define CINPUT
#include "lib/LsLib.h"
#undef CINPUT
#include "GameSetting.h"
#include "Window.h"

#define SELECT_MAX_TITLE (2)

using namespace input;

//背景を読み込む
void Title::loadGraph() {

	graph = LoadGraph(TITLE_GRAPH_NAME);
}

//更新
void Title::update() {

	//メニューセレクト
	if (Input::key.value[KEY_INPUT_UP] == 1)   select = --select % SELECT_MAX_TITLE;
	if (Input::key.value[KEY_INPUT_DOWN] == 1) select = ++select % SELECT_MAX_TITLE;

	//決定
	if (Input::key.value[KEY_INPUT_RETURN] == 1) {

		//タイトル画面
		if (select) DxLib_End();
		else window::nextWindow();
	}
}

//描画
void Title::draw() {

	//size
	int size[2] = {
	GetDrawStringWidth("START", 6),
	GetDrawStringWidth("EXIT", 6)
	};

	//背景
	DrawGraph(0, 0, graph, TRUE);

	//選択中の選択肢
	DrawBox(350, 435 + ABS(select) * 25, 466, 460 + ABS(select) * 25, sky, TRUE);

	//選択肢の表示
	DrawFormatString((WINDOW_SIZE_X / 2) - (size[0] / 2), 440, select ? white : gray15, "START");
	DrawFormatString((WINDOW_SIZE_X / 2) - (size[1] / 2), 465, select ? gray15 : white, "EXIT");
}