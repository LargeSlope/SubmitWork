#include "coordinate.h"

//�f�t�H���g�R���X�g���N�^
Coordinate::Coordinate() {

	snum = point1<int>();
	local = point1<float>();
}

//�����ݒ�t���R���X�g���N�^
Coordinate::Coordinate(point1<int>sector_num, point1<float>local) {

	this->snum = sector_num;
	this->local = local;
}