#include "GameManager.h"
#include "Window.h"
#define WINFUNC
#define CINPUT
#include "lib/LsLib.h"
#undef CINPUT
#undef WINFUNC

using namespace input;

//�ՖʊǗ�
Board GameManager::board;

//�X�R�A
int GameManager::score = 0;

//���͉\���
bool GameManager::available = true;

//���U���g���
Result GameManager::result;

//�^�C�g�����
Title GameManager::title;

//�n�C�X�R�A
int GameManager::hscore = 0;


//���������� (�߂�l 0�F���� 1�F�ُ�I��)
int GameManager::gInit() {

	TileMng::init();

	hscore = result.loadHighScore();
	result.loadBackground();

	return 0;
}

//�^�C�g����ʂ̍X�V
void GameManager::UpdateTitle() {

	title.update();
	title.draw();
}

//�Ֆʈ��艻�����i�������j
void GameManager::StableBoard() {

	//���肷��܂ŃN�C�b�N�}�b�`3���s��
	if (TileMng::quick) {

		//���艻����
		while (!TileMng::stable()) {

			TileMng::update();
		}
		TileMng::quick = false;
	}
}

//�Q�[�����C����ʂ̍X�V
void GameManager::UpdateGame() {

	//test
	int test = 0;

	//�X�R�A�y�у^�C���Ǘ���Ԃ̍X�V
	int score = TileMng::update();

	//�Ֆʈ��艻(�N�C�b�N���̂�)
	StableBoard();

	//�w�i�̕`��
	board.drawBackground();
	
	//�^�C���̕`��
	TileMng::draw();

	//�O�i�̕`��
	board.drawForeGround(score, hscore);


	//�Ֆʂ̍X�V
	if (board.update()) {

		available = false; //TimeUP���C����֎~
		board.drawTimeUP(); //"TimeUP"��\������

		//���艻��Ԃɂ���Ƃ�
		if ( TileMng::stable() ) {

			Input::reset(); //���͒l�����Z�b�g

			//3�b��C���̃��x���Ɉړ�
			if (board.fupdate()) {

				//�X�R�A��}��(�n�C�X�R�A���擾)
				hscore = result.insert(score);

				board.reset(); //�������Ԃ�3�b�J�E���^�����Z�b�g
				window::nextWindow(); //���̃��x��
			}
		}
	}
}

//���U���g��ʂ̍X�V
void GameManager::UpdateResult() {

	result.update();
	result.draw();

	if (window::getWindowNum() != 2) {

		//�{�[�h�̃��Z�b�g
		board.reset();

		//�^�C���}�l�[�W���̃��Z�b�g
		TileMng::init();

		//�N�C�b�N���[�h��L���ɂ���
		TileMng::quick = true;

		//�Ֆʂ𑀍�\�ɂ���
		available = true;
	}
}

//���x���؂�ւ�����
void GameManager::switchLevel() {

	switch (window::getWindowNum()) {
	case TITLE: UpdateTitle(); break;
	case GMAIN: UpdateGame(); break;
	case RESULT: UpdateResult(); break;
	default:break;
	}
}

//���C������
void GameManager::gMain() {

	//�E�B���h�E��0�Ԗ�(TITLE)�ɐݒ�
	window::setWindowNum( TITLE );

	//�^�C�g����ʂ̏�����
	title.loadGraph();

	//�Ֆʂ̏�����
	board = Board();

	//���C�����[�v�i�t���[���X�V�j
	while (Loop(ALL)) {

		//�}�E�X�N���b�N�I�����C�E�B���h�E�𑀍�\�ɂ���
		if (Input::mouse.detach[LEFT]) window::Available = true;

		//�}�E�X�|�C���^�ƃL�[�{�[�h�̍X�V
		if(available) Input::update(MOUSE & KEYBD);

		//�L�[�{�[�h�̍X�V
		else Input::update(KEYBD);

		//�E�B���h�E�ԍ����ƂɃ��x����؂�ւ�
		switchLevel();

		//Esc���������Ƃ��ɃQ�[�����I��������
		if (Input::key.value[KEY_INPUT_ESCAPE] == 1) break;
	}
}