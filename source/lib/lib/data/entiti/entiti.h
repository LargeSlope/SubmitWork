#include "../coordinate/coordinate.h"

//�G���e�B�e�B�N���X
class Entiti {
public:
	//���Z�ΏۃZ�N�^�t���O
	unsigned char cflag = 0;

	/* cflag�̒l��next_sector�ɑ΂���ΏۃZ�N�^
	0000 0000	current
	0000 0001	left
	0000 0010	top
	0000 0100	right
	0000 1000	bottom
	*/

	//���݃Z�N�^�̍��W
	Coordinate this_sector;

	//����Z�N�^�̍��W
	Coordinate next_sector;

	//�i�~�`�I�u�W�F�N�g�̏ꍇ�j���a
	float r;

	//���Z�N�^�̍��W�����߂�
	void getNextSector();

	//���݃Z�N�^���ړ�������
	void setThisSector();

	//���͎�t
	virtual void getInputToMove();

protected:

	//���x�x�N�g��
	point1<float> v;

	//�����x�x�N�g��
	point1<float> a;

private:

	//���Z�ΏۃZ�N�^�����߂�( �����蔻��:���ar�̉~ )
	void getCalcSector();
};