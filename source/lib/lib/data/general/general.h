#pragma once
#include "math.h"

//”Ä—pÀ”Œ^
class general {

	//®”•”
	int integer;

	//¬”•”
	float decimal;

	//2€æZ
	general mul(int i1, float f1, int i2, float f2) {

		double result = (double)(i1 * i2) + (double)(i1 * f2) + (double)(f1 * i2) + (double)(f1 * f2);
		return general((int)floor(result), (float)(result - floor(result)));
	}

public:

	//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	general() {
		integer = 0,
		decimal = 0;
	}
	general(int a, float b) {
		integer = a,
		decimal = b;
	}

	//‰ÁZ
	general operator+(general a) {
		return general(integer + a.integer, decimal + a.decimal);
	}
	//Œ¸Z
	general operator-(general a) {
		return general(integer - a.integer, decimal - a.decimal);
	}
	//æZ
	general operator*(general a) {
		return mul(integer, decimal, a.integer, a.decimal);
	}
	//œZ
	general operator/(general a) {
		return general(integer + a.integer, decimal + a.decimal);
	}
};

//•¡‘f”Œ^
class complex : general{

	//‹•”•”
};