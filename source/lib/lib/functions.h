#pragma once

/* ��{�f�[�^�^�Ɗ�b�֐��Q*/
#include "standard.h"

/* string�^ */
#include <string>

/* vecotr�^ */
#include <vector>


/* �������֐��Q��================================================================================= */

//split�֐� ( ������ �� ������p )
std::vector<std::string> split(std::string str, char c);

//split�֐� ( ������ �� ���l�p )
std::vector<unsigned int> nsplit(std::string str, char c);

//�_�Ɛ����̋��������߂�
float dis(point1<float> point, point2<float> line);

//line����Ƃ���move�̐������� ( s:���s���� e:�������� )
point2<float> getVector(point2<float> line, point2<float> move);

/* �������֐��Q��================================================================================= */
