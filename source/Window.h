#pragma once

#define WINDOWNUM 3

//�E�B���h�E�N���X
class window {

	static int State;

public:

	static bool Available; //���̃t���O��OFF�̏ꍇ�C����s�\�ɂ���

	static int nextWindow();

	static void setWindowNum(int snum);

	static int getWindowNum();
};