#define WINFUNC
#include "lib/LsLib.h"
#include "GameManager.h"

//�G���g���|�C���g
int main() {

	//DxLib�̏�����
	Init;

	//�Q�[���}�l�[�W��������
	GameManager::gInit();

	//�Q�[���}�l�[�W���X�V����
	GameManager::gMain();

	//DxLib�I������
	DxLib::DxLib_End();

	//�Q�[���I��
	return 0;
}