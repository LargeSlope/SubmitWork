#pragma once

//�ՖʊǗ��N���X
class Board {

	//�O���t�B�b�N�n���h��([0]:�w�i [1]:�O�i [2]:TimeUP)
	int graph[3] = {};

	//��������
	int time = 0;

	//�t���[�Y�^�C��
	int ftime = 0;

public:

	//�O���t�B�b�N�ǂݍ���
	Board();

	//�������Ԃ̃��Z�b�g
	void reset();

	//�Ֆʂ̍X�V(�������� false:������ true:����)
	bool update();

	//�t���[�Y�^�C���̃A�b�v�f�[�g
	bool fupdate();

	//�w�i�̕`��
	void drawBackground();

	//�O�i�̕`��
	void drawForeGround(int score, int hscore);

	//TimeUP��`��
	void drawTimeUP();
};