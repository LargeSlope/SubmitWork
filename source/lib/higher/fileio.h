#pragma once
/*///////////////////////////////////////////////////////////////////////////////////////////////////
*�y�t�@�C���W�����o�́z																				*
*	�쐬���F2019/1/26																				*
*	�X�V���F2019/1/26																				*
*	�o�[�W�����F1.0.0																				*
///////////////////////////////////////////////////////////////////////////////////////////////////*/

/* ���ʃw�b�_�t�@�C�� */
#include "../lib/common.h"

/* ���I�z�� */
#include <vector>

/* �y���O��ԁz�m�[�h�f�[�^�^ */
namespace fileio {

	/* ���j�A�^ */
	class PointLinear {

	public:

		//���j�A�m�[�h
		std::vector<point1<unsigned int>> node;

		//�ۑ�
		void save(char *filename);

		//�ǂݍ���
		void load(char *filename);
	};

	/* �|���S���^ */
	class PointPolygon {

	public:

		//�|���S���m�[�h
		std::vector<point1<unsigned int>> node;

		//�ۑ�
		void save(char *filename);

		//�ǂݍ���
		void load(char *filename);
	};

	/* �����|���S���^ */
	class DividePolygon {

	public:

		//�|���S���m�[�h
		std::vector<point1<unsigned int>> node;

		//�ۑ�
		void save(char *filename);

		//�ǂݍ���
		void load(char *filename);
	};
}