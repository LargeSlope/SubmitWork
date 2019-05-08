#include "coordinate.h"

//デフォルトコンストラクタ
Coordinate::Coordinate() {

	snum = point1<int>();
	local = point1<float>();
}

//初期設定付きコンストラクタ
Coordinate::Coordinate(point1<int>sector_num, point1<float>local) {

	this->snum = sector_num;
	this->local = local;
}