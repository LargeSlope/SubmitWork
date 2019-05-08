#include "functions.h"

//split�֐� ( ������p )
std::vector<std::string> split(std::string str, char c) {

	//�o�b�t�@
	std::string buff;

	//����
	std::vector<std::string> result;

	//������̑S�̈��T��
	for (auto it = str.begin(); it != str.end(); it++) {

		//�X�v���b�^��v��
		if ((*it) == c || (*it) == '\n' || (*it) == '\0') {

			//�o�b�t�@�����ʂɊi�[
			result.push_back( buff );
			buff = "";
		}
		//���v��
		else {

			//�o�b�t�@�ɒǉ�
			buff += (*it);
		}
	}
	//����
	return result;
}

//split�֐� ( ���l�p )
std::vector<unsigned int> nsplit(std::string str, char c) {

	//�o�b�t�@
	std::string buff;

	//����
	std::vector<unsigned int> result;

	//������̑S�̈��T��
	for (auto it = str.begin(); it != str.end(); it++) {

		//�X�v���b�^��v��
		if ((*it) == c || (*it) == '\n' || (*it) == '\0') {

			//�o�b�t�@�����ʂɊi�[
			result.push_back((unsigned int)atoi(buff.c_str()));
			buff = "";
		}
		//���v��
		else {

			//�o�b�t�@�ɒǉ�
			buff += (*it);
		}
	}
	//����
	return result;
}

//target��rad��]������
template<class T>
point1<T> rot(point1<T> origin, point1<T> target, double rad) {

	point1<T> point = target - origin;

	return(
		point1<T>(
		(T)(cos(rad) * point.x - sin(rad) * point.y + origin.x),
			(T)(sin(rad) * point.x + cos(rad) * point.y + origin.y)
			));
}

//�_�Ɛ����̋��������߂�
float dis(point1<float> point, point2<float> line) {

	//�_�Ɠ_�̋���
	float length_s = (float)point2<float>(point, line.s).length(),
		length_e = (float)point2<float>(point, line.e).length();

	//��{�p�x�̈�ɕϊ�
	point2<float> Hline = line - line.s;
	point1<float> Point = point - line.s;

	Hline = point2<float>(point1<float>(), rot(Hline.s, Hline.e, -line.angle()));
	Point = rot(point1<float>(), Point, -line.angle());


	//��������
	if (Hline.s.x <= Point.x && Point.x <= Hline.e.x) {

		return (float)(((Point.y) >= 0) ? (Point.y) : -(Point.y));
	}
	else if (length_s < length_e) {

		return length_s;
	}
	else {

		return length_e;
	}
	return -1;
}

//line����Ƃ���move�̐������� ( s:���s e:���� )
point2<float> getVector(point2<float> line, point2<float> move) {

	//���̂̈ړ��x�N�g��
	point1<float> mvec = move.vec();

	//���̃x�N�g��
	point1<float> lvec = line.vec();

	//����
	return point2<float>(
		lvec * ((mvec * lvec) / pow(lvec.length(), 2.f)),
		mvec - lvec * ((mvec * lvec) / pow(lvec.length(), 2.f)));
}
