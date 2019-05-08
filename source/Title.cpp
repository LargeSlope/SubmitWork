#include "Title.h"
#define CINPUT
#include "lib/LsLib.h"
#undef CINPUT
#include "GameSetting.h"
#include "Window.h"

#define SELECT_MAX_TITLE (2)

using namespace input;

//�w�i��ǂݍ���
void Title::loadGraph() {

	graph = LoadGraph(TITLE_GRAPH_NAME);
}

//�X�V
void Title::update() {

	//���j���[�Z���N�g
	if (Input::key.value[KEY_INPUT_UP] == 1)   select = --select % SELECT_MAX_TITLE;
	if (Input::key.value[KEY_INPUT_DOWN] == 1) select = ++select % SELECT_MAX_TITLE;

	//����
	if (Input::key.value[KEY_INPUT_RETURN] == 1) {

		//�^�C�g�����
		if (select) DxLib_End();
		else window::nextWindow();
	}
}

//�`��
void Title::draw() {

	//size
	int size[2] = {
	GetDrawStringWidth("START", 6),
	GetDrawStringWidth("EXIT", 6)
	};

	//�w�i
	DrawGraph(0, 0, graph, TRUE);

	//�I�𒆂̑I����
	DrawBox(350, 435 + ABS(select) * 25, 466, 460 + ABS(select) * 25, sky, TRUE);

	//�I�����̕\��
	DrawFormatString((WINDOW_SIZE_X / 2) - (size[0] / 2), 440, select ? white : gray15, "START");
	DrawFormatString((WINDOW_SIZE_X / 2) - (size[1] / 2), 465, select ? gray15 : white, "EXIT");
}