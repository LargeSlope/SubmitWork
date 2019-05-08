#include "entiti.h"

//���Z�N�^�̍��W�����߂�
void Entiti::getNextSector() {

	//���ʃo�b�t�@
	Coordinate result = this_sector;

	//���t���[���̈ʒu(���[�J��)
	result.local += (v + a);

	//���t���[���Z�N�^�����߂�
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

	//���Z�N�^���X�V
	next_sector = result;

	//���Z�ΏۃZ�N�^�����߂�
	getCalcSector();
}

//���Z�ΏۃZ�N�^�����߂�( �����蔻��:���ar�̉~ )
void Entiti::getCalcSector() {

	//r�����̎��͍����v�Z�Ώ�
	if (next_sector.local.x < r) {
		cflag |= 0b00000001;
	}
	//r�ȏ�̎��͉E���v�Z�Ώ�
	if (next_sector.local.x >= 300.f - r) {
		cflag |= 0b00000010;
	}
	//r�����̎��͏���v�Z�Ώ�
	if (next_sector.local.y < r) {
		cflag |= 0b00000100;
	}
	//r�ȏ�̎��͉����v�Z�Ώ�
	if (next_sector.local.y >= 300.f - r) {
		cflag |= 0b00001000;
	}
}
//���͎�t
void Entiti::getInputToMove() { }

//���݃Z�N�^���ړ�������
void Entiti::setThisSector() {

	//���t���[�����W�ōX�V
	this_sector = next_sector;
}