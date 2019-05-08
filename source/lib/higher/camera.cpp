#include "camera.h"

using namespace camera;

//絶対座標系に対するカメラ座標 ( 左上 )
point1<int> Camera::point;

//カメラが距離の2乗に反比例する速度で移動するシネマ効果
void Camera::move(point1<int> next_coordinate, int level) {

	//カメラの移動先
	point1<float> v = next_coordinate - point;

	//移動先座標とカメラの距離
	float movement = (float)point2<int>(point, next_coordinate).length();

	//移動距離の2乗に反比例
	v /= pow(movement + level, 2);
}

//カメラ位置をアクタ位置に合わせる
void Camera::adjust(point1<int> actor) {

	point.x = actor.x - WINDOW_SIZE_X / 2;
	point.y = actor.y - WINDOW_SIZE_Y / 2;
}