#pragma once
#include "../lib/common.h"
#include "DxLib.h"

#define MOUSE	(0x0E)	//マウス状態を更新
#define KEYBD	(0x0D)	//キーボード状態を更新
#define XINPUT	(0x0B)	//ゲームパッド状態を更新

#define LEFT 0
#define RIGHT 1

namespace input {

	//入力管理系
	class Input {

	public:
		//マウス状態
		static class Mouse {
		public:
			point1<int> s_point;		//ドラッグ開始位置
			point1<int> e_point;		//ドラッグ終了位置
			point1<int> point;			//マウスポインタ座標
			int push[2];				//0:LEFT  1:RIGHT  push時間
			bool detach[2] = { false };	//デタッチフラグ
			int wheel = 0;				//マウスホイール

			void update();
		}mouse;

		//キーボード状態
		static class Key {
		public:
			int value[256];			//キー入力時間

			void update();
		}key;

		//ゲームパッド状態
		static XINPUT_STATE xinput;

		//入力状態を更新
		static void update( int update );

		//入力状態をリセット
		static void reset();
	};
}