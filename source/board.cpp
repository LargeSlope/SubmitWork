#include "board.h"
#include "DxLib.h"
#include "GameSetting.h"
#include "lib/LsLib.h"

//�O���t�B�b�N�ǂݍ���
Board::Board() {

	reset(); //�������Ԃ̃��Z�b�g
	graph[0] = LoadGraph(BOARD_GRAPH_NAME);  //�w�i
	graph[1] = LoadGraph(BOARD_GRAPH_NAME2); //�O�i
	graph[2] = LoadGraph(BOARD_GRAPH_NAME3); //TimeUP

	//�t�H���g�̎�ނ�ݒ�
	ChangeFont("���C���I");

	//�t�H���g�T�C�Y�̎w��
	SetFontSize(20);
}

//�������Ԃ̃��Z�b�g
void Board::reset() {

	time = 0;
	ftime = 0;
}

//�Ֆʂ̍X�V(�������� false:������ true:����)
bool Board::update() {

	if (time < TIME_MAX) time++;
	else return true;
	return false;
}

//�t���[�Y�^�C���̃A�b�v�f�[�g
bool Board::fupdate() {

	if (ftime < FTIME_MAX) ftime++;
	else return true;
	return false;
}

//�w�i�̕`��
void Board::drawBackground() {

	DrawGraph(0, 0, graph[0], TRUE);
}

//�O�i�̕`��
void Board::drawForeGround(int score, int hscore) {

	//�O�i
	DrawGraph(0, 0, graph[1], TRUE);

	//�������Ԃ̕`��
	DrawBox(681, 186, 781, 206, white, FALSE);
	DrawBox(681, 186, 781 - (int)(100 * ((double)time / TIME_MAX)), 206, white, TRUE);
	DrawFormatString(735, 231, white, "%d", 30 - time / 60);

	//�X�R�A�̕`��
	DrawFormatString(53, 138, white, "%d", score);

	//�n�C�X�R�A�̕`��
	DrawFormatString(53, 257, white, "%d", hscore);
}

//TimeUP��`��
void Board::drawTimeUP() {

	DrawGraph(0, 0, graph[2], TRUE);
}