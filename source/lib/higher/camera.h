#pragma once
#include "../lib/common.h"
#include "DxLib.h"

namespace camera {

	class Camera {

	public:
		//��΍��W�n�ɑ΂���J�������W ( ���� )
		static point1<int> point;

		//�J������������2��ɔ���Ⴗ�鑬�x�ňړ�����V�l�}����
		static void move(point1<int> next_coordinate, int level);

		//�J�����ʒu���A�N�^�ʒu�ɍ��킹��
		static void adjust(point1<int> actor);

		//�`��̓������
		
	};
}