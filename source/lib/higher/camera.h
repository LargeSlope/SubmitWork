#pragma once
#include "../lib/common.h"
#include "DxLib.h"

namespace camera {

	class Camera {

	public:
		//絶対座標系に対するカメラ座標 ( 左上 )
		static point1<int> point;

		//カメラが距離の2乗に反比例する速度で移動するシネマ効果
		static void move(point1<int> next_coordinate, int level);

		//カメラ位置をアクタ位置に合わせる
		static void adjust(point1<int> actor);

		//描画の特殊効果
		
	};
}