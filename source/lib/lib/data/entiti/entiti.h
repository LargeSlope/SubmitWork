#include "../coordinate/coordinate.h"

//エンティティクラス
class Entiti {
public:
	//演算対象セクタフラグ
	unsigned char cflag = 0;

	/* cflagの値とnext_sectorに対する対象セクタ
	0000 0000	current
	0000 0001	left
	0000 0010	top
	0000 0100	right
	0000 1000	bottom
	*/

	//現在セクタの座標
	Coordinate this_sector;

	//次回セクタの座標
	Coordinate next_sector;

	//（円形オブジェクトの場合）半径
	float r;

	//次セクタの座標を求める
	void getNextSector();

	//現在セクタを移動させる
	void setThisSector();

	//入力受付
	virtual void getInputToMove();

protected:

	//速度ベクトル
	point1<float> v;

	//加速度ベクトル
	point1<float> a;

private:

	//演算対象セクタを求める( 当たり判定:半径rの円 )
	void getCalcSector();
};