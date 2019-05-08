#include "Window.h"

//ウィンドウ遷移状態
int window::State = 0;

//ウィンドウ操作可能状態
bool window::Available = false;


//ウィンドウを進める
int window::nextWindow() {

	Available = false;
	State = (++State % WINDOWNUM);
	return State;
}

//ウィンドウの番号を指定
void window::setWindowNum(int snum) {

	Available = false;
	State = snum;
}

//ウィンドウの番号を取得
int window::getWindowNum() {

	return State;
}