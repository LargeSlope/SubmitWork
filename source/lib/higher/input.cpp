#include "input.h"
#include "DxLib.h"

using namespace input;

//static�t�B�[���h
Input::Mouse Input::mouse;
Input::Key Input::key;
XINPUT_STATE Input::xinput;

//�}�E�X���͍X�V
void Input::Mouse::update() {

	//���̓o�b�t�@
	int input_buf = GetMouseInput();

	//�����̓o�b�t�@
	static int old_input_buf;

	//�}�E�X�|�C���^�̈ʒu���擾
	GetMousePoint(&point.x, &point.y);

	//�}�E�X�̃N���b�N��Ԃ��擾
	if (input_buf & MOUSE_INPUT_LEFT) push[LEFT]++; else push[LEFT] = 0;
	if( input_buf & MOUSE_INPUT_RIGHT ) push[RIGHT]++; else push[RIGHT] = 0;

	//�h���b�O���߂̈ʒu���擾
	if ( push[LEFT] == 1 ) {

		s_point = point;
	}

	//�f�^�b�`�t���O���擾
	detach[LEFT] = ((push[LEFT] == 0) && ((old_input_buf & MOUSE_INPUT_LEFT) == 1));
	detach[RIGHT] = ((push[RIGHT] == 0) && ((old_input_buf & MOUSE_INPUT_RIGHT) == 1));

	//�h���b�O�I���ʒu���擾
	if ( detach[LEFT] ) {

		e_point = point;
	}

	//�}�E�X�z�C�[���̈ʒu���擾
	wheel = GetMouseWheelRotVol();

	//�����̓o�b�t�@�X�V
	old_input_buf = input_buf;
}

void Input::Key::update() {

	char karr[256] = "";

	//�S�ẴL�[���͂��擾
	GetHitKeyStateAll(karr);

	//���͒��̃L�[�́C�J�E���g�A�b�v
	for (int i = 0; i < 256; i++) {

		if ( karr[i] ) {

			value[i]++;
		}
		else {

			value[i] = 0;
		}
	}
}

//���͏�Ԃ��X�V
void Input::update(int update) {

	if ( !( update & 0x01 ) ) mouse.update();
	if ( !( update & 0x02 ) ) key.update();
	if ( !( update & 0x04 ) ) GetJoypadXInputState( DX_INPUT_PAD1, &xinput );
}

//���͏�Ԃ����Z�b�g
void Input::reset() {

	mouse = Mouse();
	key = Key();
}