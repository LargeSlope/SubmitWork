#pragma once

//�^�C��
class Tile {

	//�^�C���l
	unsigned char value;
	/*
	0:����  5:����    10:�c��    15:�͈͐�
	1:����  6:����    11:�c��    16:�͈͗�
	2:��퉩  7:����    12:�c��    17:�͈͉�
	3:����  8:����    13:�c��    18:�͈͐�
	4:��펇  9:����    14:�c��    19:�͈͎�
	*/

	//�O���t�B�b�N�n���h�� (DXLIB�ˑ�)
	static int ghandle[25];

	//�O���t�B�b�N�n���h���i�A���[�C���[�W�j
	static int ahandle[3];

	//�����t���[��(0�`25�t���[�� ���摜1��5�t���[�� * 5��)
	int vanish_frame = 0;

	//�����t���[��(12 * count �t���[��)
	int fall_frame = 0;

public:

	//�����\��t���O
	bool vanish = false;

	//�O���t�B�b�N��ǂݍ���((48[px],48[px])*5tiles*5tiles)(DXLIB�ˑ�)
	static void loadGraph(const char *fileName);

	//�^�C���̌���
	static void exchange(Tile &a, Tile &b);

	//������
	void setValue(const unsigned char Value);

	//�l�擾(0�`4)
	int  getValueColor();

	//�����̎��Ԃ�i�߂�(true:�����@false:������)
	bool advanceVAnim();

	//�N�C�b�N����
	void quickVAnim();

	//�������Ԃ����Z�b�g����
	void resetVAnim();

	//�������Ԃ��擾����
	int getVFrame();

	//������Ԃ��擾����(����false:�����ς݂Ȃ�1�Ctrue:�������Ȃ�1)
	int getVState(bool type = false);

	//�������Ԃ�i�߂�
	void advanceFAnim(int count);

	//�������Ԃ����Z�b�g����
	void resetFallFrame();

	//������Ԃ̎擾
	int getFState();

	//����������Ԃ��擾����(true:���� false:������)
	bool getFFinished(int count);

	//�^�C�v�擾(0:��� 1:�� 2:�c 3:�͈�)
	int  getValueType();

	//�`��(vanish:�j��x(0�`4))(DXLIB�ˑ�)
	void draw(const int& xPos, const int& yPos);
};