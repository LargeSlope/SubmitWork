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


//�n�C�X�R�A������ǂݍ���
int Result::loadHighScore() {

	//�o�b�t�@
	char score_buff[10] = "";

	//�t�@�C���I�[�v��
	int fscore = FileRead_open(RESULT_HISCORE);

	//�n�C�X�R�A��������
	hiscore = vector<int>(HISCORE_NUM);

	//�t�@�C���̓ǂݍ���
	for (int i = 0; i < HISCORE_NUM; i++) {

		//�t�@�C���̏I�[�̎��Cbreak
		if (FileRead_eof(fscore)) break;

		//�t�@�C����1�s�ǂݏo��
		FileRead_gets(score_buff, 10, fscore);

		//�n�C�X�R�A���i�[
		hiscore[i] = atoi(score_buff);
	}
	//�t�@�C�������
	FileRead_close(fscore);

	return hiscore[0];
}

//���U���g��ʂ̔w�i��ǂݍ���
void Result::loadBackground() {

	graph = LoadGraph(RESULT_GRAPH_NAME);
}

//���j���[
void Result::update() {

	//���j���[�Z���N�g
	if (Input::key.value[KEY_INPUT_UP] == 1)   select = --select % SELECT_MAX;
	if (Input::key.value[KEY_INPUT_DOWN] == 1) select = ++select % SELECT_MAX;

	//����
	if (Input::key.value[KEY_INPUT_RETURN] == 1) {

		//�n�C�X�R�A��ۑ�
		saveHighScore();

		//�^�C�g�����
		if (select) window::setWindowNum(1);
		else window::nextWindow();
	}
}

//�`�悷��
void Result::draw() {

	int str_width[2] = {

		GetDrawStringWidth("TITLE", 6),
		GetDrawStringWidth("CONTINUE", 8)
	};

	//�w�i
	DrawGraph(0, 0, graph, TRUE);

	//�n�C�X�R�A
	for (int i = 0; i < HISCORE_NUM; i++) {

		if (i == score_index) DrawBox(304, 252 + 25 * i, 550, 274 + 25 * i, white, FALSE);
		DrawFormatString(304, 254 + 25 * i, white, "%3d.", i + 1);
		DrawFormatString(454, 254 + 25 * i, white, "%5d", hiscore[i]);
	}

	//���j���[
	DrawBox(340, 515 + ABS(select) * 25, 476, 540 + ABS(select) * 25, sky, TRUE);

	DxLib::DrawFormatString((WINDOW_SIZE_X / 2) - (str_width[0] / 2), 520, select ? white : gray15, "TITLE");
	DxLib::DrawFormatString((WINDOW_SIZE_X / 2) - (str_width[1] / 2), 544, select ? gray15 : white, "CONTINUE");
}

//���ʂ�ۑ�
void Result::saveHighScore() {

	ofstream ofs;

	//�X�R�A�t�@�C�����I�[�v��
	ofs.open(RESULT_HISCORE, ios::out);

	//���l�f�[�^�𕶎���ɕϊ�
	for (int i = 0; i < HISCORE_NUM; i++) {

		ofs << to_string(hiscore[i]).c_str() << endl;
	}

	//�t�@�C���N���[�Y
	ofs.close();
}

//�n�C�X�R�A��}������
int Result::insert(int score) {

	//�X�R�A��}��
	hiscore.push_back(score);

	//�~���\�[�g
	sort(hiscore.begin(), hiscore.end(), std::greater<int>());

	//���T�C�Y
	hiscore.resize(HISCORE_NUM);

	//�n�C�X�R�A�̈ʒu�����߂�
	for (int i = 0; i < HISCORE_NUM; i++) {

		if (hiscore[i] == score) score_index = i;
	}

	return hiscore[0];
}