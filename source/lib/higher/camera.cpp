#include "camera.h"

using namespace camera;

//��΍��W�n�ɑ΂���J�������W ( ���� )
point1<int> Camera::point;

//�J������������2��ɔ���Ⴗ�鑬�x�ňړ�����V�l�}����
void Camera::move(point1<int> next_coordinate, int level) {

	//�J�����̈ړ���
	point1<float> v = next_coordinate - point;

	//�ړ�����W�ƃJ�����̋���
	float movement = (float)point2<int>(point, next_coordinate).length();

	//�ړ�������2��ɔ����
	v /= pow(movement + level, 2);
}

//�J�����ʒu���A�N�^�ʒu�ɍ��킹��
void Camera::adjust(point1<int> actor) {

	point.x = actor.x - WINDOW_SIZE_X / 2;
	point.y = actor.y - WINDOW_SIZE_Y / 2;
}