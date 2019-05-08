#pragma once
/* ���U���g��ʂ��Ǘ�����N���X�ł� */
#include <vector>

#define HISCORE_NUM (10)
#define SELECT_MAX (2)

using namespace std;

//���U���g�N���X
class Result {

	int graph = 0; //�O���t�B�b�N�n���h��

	vector<int> hiscore; //High Score

	int select = 0; //���j���[�̃Z���N�g�ԍ�(0:TITLE ��0:CONTINUE)

	int score_index = 0; //����̃X�R�A����

public:

	//�n�C�X�R�A������ǂݍ���
	int loadHighScore();

	//���U���g��ʂ̔w�i��ǂݍ���
	void loadBackground();

	//���ʂ�ۑ�
	void saveHighScore();

	//���j���[
	void update();

	//�n�C�X�R�A��}������
	int insert(int score);

	//�`�悷��
	void draw();
};