#pragma once
#include "TileMng.h"
#include "board.h"
#include "Result.h"
#include "Title.h"

#define TITLE (0)
#define GMAIN (1)
#define RESULT (2)

//�Q�[���}�l�[�W��
class GameManager {

	//�ՖʊǗ�
	static Board board;

	//���U���g���
	static Result result;

	//�^�C�g�����
	static Title title;

	//�X�R�A
	static int score;

	//�n�C�X�R�A
	static int hscore;

	//���͉\���
	static bool available;

	//�Ֆʈ��艻����
	static void StableBoard();

	//�^�C�g����ʂ̍X�V
	static void UpdateTitle();

	//�Q�[�����C����ʂ̍X�V
	static void UpdateGame();

	//���U���g��ʂ̍X�V
	static void UpdateResult();

	//���x���؂�ւ�����
	static void switchLevel();

public:

	//���������� (�߂�l 0�F���� 1�F�ُ�I��)
	static int gInit();

	//���C������
	static void gMain();
};