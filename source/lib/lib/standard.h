#pragma once
/*///////////////////////////////////////////////////////////////////////////////////////////////////
*【基本データ型定義】																				*
*	作成日：2019/1/26																				*
*	更新日：2019/1/26																				*
*	バージョン：1.0.0																				*
///////////////////////////////////////////////////////////////////////////////////////////////////*/

/* エンティティクラス */
#include "data/entiti/entiti.h"

/* ゲームレベルクラス */
#include "data/level/level.h"

/* 点座標クラス */
#include "data/point1/point1.h"

/* 面座標クラス */
#include "data/point2/point2.h"

/* ▽座標系クラス関数群▽================================================================================= */

//包含関係 ( point2 < point1 )
template<class T>
bool operator<(point2<T> sq, point1<T> pt) {

	if( (((sq.s.x <= pt.x) && (pt.x < sq.e.x)) || ((sq.e.x <= pt.x) && (pt.x < sq.s.x))) &&
		(((sq.s.y <= pt.y) && (pt.y < sq.e.y)) || ((sq.e.y <= pt.y) && (pt.y < sq.s.y)))
		) return true;
	return false;
}

//ベクターラウンド関数
template<class T>
point1<T> vround(point1<T> vec) {
	return( //小数点以下6桁に抑える
		(float)floor(vec.x * pow(10.f, 2)) / pow(10.f, 2),
		(float)floor(vec.y * pow(10.f, 2)) / pow(10.f, 2));
}

/* △座標系クラス関数群△================================================================================= */