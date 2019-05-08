#pragma once
#include "math.h"

//�ėp�����^
class general {

	//������
	int integer;

	//������
	float decimal;

	//2����Z
	general mul(int i1, float f1, int i2, float f2) {

		double result = (double)(i1 * i2) + (double)(i1 * f2) + (double)(f1 * i2) + (double)(f1 * f2);
		return general((int)floor(result), (float)(result - floor(result)));
	}

public:

	//�R���X�g���N�^
	general() {
		integer = 0,
		decimal = 0;
	}
	general(int a, float b) {
		integer = a,
		decimal = b;
	}

	//���Z
	general operator+(general a) {
		return general(integer + a.integer, decimal + a.decimal);
	}
	//���Z
	general operator-(general a) {
		return general(integer - a.integer, decimal - a.decimal);
	}
	//��Z
	general operator*(general a) {
		return mul(integer, decimal, a.integer, a.decimal);
	}
	//���Z
	general operator/(general a) {
		return general(integer + a.integer, decimal + a.decimal);
	}
};

//���f���^
class complex : general{

	//������
};