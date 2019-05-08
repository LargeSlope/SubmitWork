#pragma once
#include "Tiles.h"
#include "GameSetting.h"

//�^�C���I�u�W�F�N�g�Ǘ��N���X
class TileMng {

	static Tile tile[BOARD_SIZE_NUM];

	static int score;

	//�`�� (�߂�l�F�h���b�O���̃^�C����index)
	static int _draw();

	//�h���b�O�ɂ�����
	static void exchange();

	//�}�b�`3(�����w��)
	static void _match3(int index, int dir);

	//�}�b�`3
	static void match3();

	//�}�b�`3�p�����ς݃`�F�b�N
	static bool checkVanish(int index1, int index2, int index3);

	//1�s����
	static void vanishLine(int index);

	//1�����
	static void vanishRow(int index);

	//�͈͏���
	static void vanishSq(int index);

	//����^�C���̏���
	static void vanishSpecial();

	//�����ɂ�����
	static void fexchange(int index1, int count);

	//����
	static void vanish();

	//����
	static void fall();

	//��U
	static void fill();

public:

	//�N�C�b�N���[�h
	static bool quick;

	//�����Ԃ��擾(�߂�ltrue:���� false:�s����)
	static bool stable();

	//�^�C���̏�����
	static void init();

	//�X�V
	static int update();

	//�`��
	static void draw();
};