#pragma once
#include "../lib/common.h"
#include "DxLib.h"

#define MOUSE	(0x0E)	//�}�E�X��Ԃ��X�V
#define KEYBD	(0x0D)	//�L�[�{�[�h��Ԃ��X�V
#define XINPUT	(0x0B)	//�Q�[���p�b�h��Ԃ��X�V

#define LEFT 0
#define RIGHT 1

namespace input {

	//���͊Ǘ��n
	class Input {

	public:
		//�}�E�X���
		static class Mouse {
		public:
			point1<int> s_point;		//�h���b�O�J�n�ʒu
			point1<int> e_point;		//�h���b�O�I���ʒu
			point1<int> point;			//�}�E�X�|�C���^���W
			int push[2];				//0:LEFT  1:RIGHT  push����
			bool detach[2] = { false };	//�f�^�b�`�t���O
			int wheel = 0;				//�}�E�X�z�C�[��

			void update();
		}mouse;

		//�L�[�{�[�h���
		static class Key {
		public:
			int value[256];			//�L�[���͎���

			void update();
		}key;

		//�Q�[���p�b�h���
		static XINPUT_STATE xinput;

		//���͏�Ԃ��X�V
		static void update( int update );

		//���͏�Ԃ����Z�b�g
		static void reset();
	};
}