/*///////////////////////////////////////////////////////////////////////////////////////////////////
*�y�t�@�C���W�����o�͎����z																			*
*	�쐬���F2019/1/26																				*
*	�X�V���F2019/1/26																				*
*	�o�[�W�����F1.0.0																				*
///////////////////////////////////////////////////////////////////////////////////////////////////*/
#include "fileio.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace fileio;

//�ۑ�
void PointLinear::save(char *filename) {

	//�t�@�C���X�g���[��
	std::ofstream ofs;

	//�t�@�C���I�[�v��
	ofs.open(filename, std::ios::out);

	//�f�[�^�̊i�[
	for (auto it = node.begin(); it != node.end(); it++) {

		//������ɒǉ�
		ofs << ((*it).x) << "," << ((*it).y) << std::endl;
	}

	//�t�@�C���N���[�Y
	ofs.close();
}

//�ǂݍ���
void PointLinear::load(char *filename) {

	//�t�@�C���X�g���[��
	std::ifstream ifs;

	//�t�@�C��1�s�ǂݍ��݃o�b�t�@
	std::string line;

	//�t�@�C���I�[�v��
	ifs.open(filename, std::ios::in);

	//�f�[�^�̎擾
	while (std::getline(ifs, line)) {

		//string��point1�^�Ƀp�[�X
		node.push_back(point1<unsigned int>());
	}

	//�t�@�C���N���[�Y
	ifs.close();
}

//�ۑ�
void PointPolygon::save(char *filename) {


}

//�ǂݍ���
void PointPolygon::load(char *filename) {


}

//�ۑ�
void DividePolygon::save(char *filename) {


}

//�ǂݍ���
void DividePolygon::load(char *filename) {


}