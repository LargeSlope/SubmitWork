#include "../point1/point1.h"

//座標クラス(汎用座標)
class Coordinate {
public:
	//デフォルトコンストラクタ
	Coordinate();

	//初期設定付きコンストラクタ
	Coordinate(point1<int>sector_num, point1<float>local);

	//セクタ番号
	point1<int> snum;

	//ローカル座標
	point1<float> local;
};