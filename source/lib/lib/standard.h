#pragma once
/*///////////////////////////////////////////////////////////////////////////////////////////////////
*�y��{�f�[�^�^��`�z																				*
*	�쐬���F2019/1/26																				*
*	�X�V���F2019/1/26																				*
*	�o�[�W�����F1.0.0																				*
///////////////////////////////////////////////////////////////////////////////////////////////////*/

/* �G���e�B�e�B�N���X */
#include "data/entiti/entiti.h"

/* �Q�[�����x���N���X */
#include "data/level/level.h"

/* �_���W�N���X */
#include "data/point1/point1.h"

/* �ʍ��W�N���X */
#include "data/point2/point2.h"

/* �����W�n�N���X�֐��Q��================================================================================= */

//��܊֌W ( point2 < point1 )
template<class T>
bool operator<(point2<T> sq, point1<T> pt) {

	if( (((sq.s.x <= pt.x) && (pt.x < sq.e.x)) || ((sq.e.x <= pt.x) && (pt.x < sq.s.x))) &&
		(((sq.s.y <= pt.y) && (pt.y < sq.e.y)) || ((sq.e.y <= pt.y) && (pt.y < sq.s.y)))
		) return true;
	return false;
}

//�x�N�^�[���E���h�֐�
template<class T>
point1<T> vround(point1<T> vec) {
	return( //�����_�ȉ�6���ɗ}����
		(float)floor(vec.x * pow(10.f, 2)) / pow(10.f, 2),
		(float)floor(vec.y * pow(10.f, 2)) / pow(10.f, 2));
}

/* �����W�n�N���X�֐��Q��================================================================================= */