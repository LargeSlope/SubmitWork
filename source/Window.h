#pragma once

#define WINDOWNUM 3

//ウィンドウクラス
class window {

	static int State;

public:

	static bool Available; //このフラグがOFFの場合，操作不能にする

	static int nextWindow();

	static void setWindowNum(int snum);

	static int getWindowNum();
};