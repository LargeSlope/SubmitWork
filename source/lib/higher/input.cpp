#include "input.h"
#include "DxLib.h"

using namespace input;

//staticフィールド
Input::Mouse Input::mouse;
Input::Key Input::key;
XINPUT_STATE Input::xinput;

//マウス入力更新
void Input::Mouse::update() {

	//入力バッファ
	int input_buf = GetMouseInput();

	//旧入力バッファ
	static int old_input_buf;

	//マウスポインタの位置を取得
	GetMousePoint(&point.x, &point.y);

	//マウスのクリック状態を取得
	if (input_buf & MOUSE_INPUT_LEFT) push[LEFT]++; else push[LEFT] = 0;
	if( input_buf & MOUSE_INPUT_RIGHT ) push[RIGHT]++; else push[RIGHT] = 0;

	//ドラッグ初めの位置を取得
	if ( push[LEFT] == 1 ) {

		s_point = point;
	}

	//デタッチフラグを取得
	detach[LEFT] = ((push[LEFT] == 0) && ((old_input_buf & MOUSE_INPUT_LEFT) == 1));
	detach[RIGHT] = ((push[RIGHT] == 0) && ((old_input_buf & MOUSE_INPUT_RIGHT) == 1));

	//ドラッグ終了位置を取得
	if ( detach[LEFT] ) {

		e_point = point;
	}

	//マウスホイールの位置を取得
	wheel = GetMouseWheelRotVol();

	//旧入力バッファ更新
	old_input_buf = input_buf;
}

void Input::Key::update() {

	char karr[256] = "";

	//全てのキー入力を取得
	GetHitKeyStateAll(karr);

	//入力中のキーは，カウントアップ
	for (int i = 0; i < 256; i++) {

		if ( karr[i] ) {

			value[i]++;
		}
		else {

			value[i] = 0;
		}
	}
}

//入力状態を更新
void Input::update(int update) {

	if ( !( update & 0x01 ) ) mouse.update();
	if ( !( update & 0x02 ) ) key.update();
	if ( !( update & 0x04 ) ) GetJoypadXInputState( DX_INPUT_PAD1, &xinput );
}

//入力状態をリセット
void Input::reset() {

	mouse = Mouse();
	key = Key();
}