#include "../point1/point1.h"

//���W�N���X(�ėp���W)
class Coordinate {
public:
	//�f�t�H���g�R���X�g���N�^
	Coordinate();

	//�����ݒ�t���R���X�g���N�^
	Coordinate(point1<int>sector_num, point1<float>local);

	//�Z�N�^�ԍ�
	point1<int> snum;

	//���[�J�����W
	point1<float> local;
};