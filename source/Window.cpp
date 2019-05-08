#include "Window.h"

//�E�B���h�E�J�ڏ��
int window::State = 0;

//�E�B���h�E����\���
bool window::Available = false;


//�E�B���h�E��i�߂�
int window::nextWindow() {

	Available = false;
	State = (++State % WINDOWNUM);
	return State;
}

//�E�B���h�E�̔ԍ����w��
void window::setWindowNum(int snum) {

	Available = false;
	State = snum;
}

//�E�B���h�E�̔ԍ����擾
int window::getWindowNum() {

	return State;
}