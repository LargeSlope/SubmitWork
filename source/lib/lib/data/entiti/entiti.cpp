#include "entiti.h"

//次セクタの座標を求める
void Entiti::getNextSector() {

	//結果バッファ
	Coordinate result = this_sector;

	//次フレームの位置(ローカル)
	result.local += (v + a);

	//次フレームセクタを求める
	while (result.local.x < 0.f) {

		result.snum.x--;
		result.local.x += 300.f;
	}

	while (result.local.x >= 300.f) {

		result.snum.x++;
		result.local.x -= 300.f;
	}

	while (result.local.y < 0.f) {

		result.snum.y--;
		result.local.y += 300.f;
	}

	while (result.local.y >= 300.f) {

		result.snum.y++;
		result.local.y -= 300.f;
	}

	//次セクタを更新
	next_sector = result;

	//演算対象セクタを求める
	getCalcSector();
}

//演算対象セクタを求める( 当たり判定:半径rの円 )
void Entiti::getCalcSector() {

	//r未満の時は左も計算対象
	if (next_sector.local.x < r) {
		cflag |= 0b00000001;
	}
	//r以上の時は右も計算対象
	if (next_sector.local.x >= 300.f - r) {
		cflag |= 0b00000010;
	}
	//r未満の時は上も計算対象
	if (next_sector.local.y < r) {
		cflag |= 0b00000100;
	}
	//r以上の時は下も計算対象
	if (next_sector.local.y >= 300.f - r) {
		cflag |= 0b00001000;
	}
}
//入力受付
void Entiti::getInputToMove() { }

//現在セクタを移動させる
void Entiti::setThisSector() {

	//次フレーム座標で更新
	this_sector = next_sector;
}