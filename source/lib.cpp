#include "lib.h"
#define CINPUT
#include "lib/LsLib.h"
#undef CINPUT
#include "GameSetting.h"

using namespace input;

//�h���b�O���̃C���f�b�N�X�擾
int getDragIndex() {

	int index_x = (Input::mouse.s_point.x - BOARD_SPOINT_X) / TILE_PXSIZE_X;
	int index_y = (Input::mouse.s_point.y - BOARD_SPOINT_Y) / TILE_PXSIZE_Y;
	return (index_x + index_y * BOARD_SIZE_X);
}

//�h���b�O����
bool drag() {

	//�h���b�O�͈͓��Ƀh���b�O�J�n�|�C���g�����݂��邱��
	bool result1 = BOARD_AREA < Input::mouse.s_point;

	//�h���b�O���ł��邱��
	bool result2 = Input::mouse.push[0] > 0;

	return result1 && result2;
}

//�h���b�O��������
bool fdrag() {

	//�h���b�O�͈͓��Ƀh���b�O�J�n�E�I���|�C���g�����݂��邱��
	bool result1 = BOARD_AREA < Input::mouse.s_point;
	bool result2 = BOARD_AREA < Input::mouse.e_point;

	//�h���b�O���삪�I����������
	bool result3 = Input::mouse.detach[LEFT];

	return (result1 && result2 && result3);
}

/*���o�[�X�֐��ɂ���*/
//���}�̂悤�ɁC�������Ɍ������ĒT������悤�Cindex�̒�`��ύX���܂��D
//�E������C1��T�����I������C��(��)�̗��T�����܂��D
//�Z�Z�Z�Z�Z�Z�Z������
//�Z�Z�Z�Z�Z�Z�Z������
//�Z�Z�Z�Z�Z�Z�Z������
//�Z�Z�Z�Z�Z�Z�Z������
//�Z�Z�Z�Z�Z�Z�Z������
//�Z�Z�Z�Z�Z�Z�Z������
//�Z�Z�Z�Z�Z�Z�Z������
//�Z�Z�Z�Z�Z�Z�Z������
//�Z�Z�Z�Z�Z�Z�Z������
//�Z�Z�Z�Z�Z�Z�c�B�A�@


//index�̃��o�[�X�֐�
int reverse(int index) {

	int index_x = BOARD_SIZE_X - (index / BOARD_SIZE_Y) - 1;
	int index_y = BOARD_SIZE_Y - (index % BOARD_SIZE_Y) - 1;

	return (index_x + index_y * BOARD_SIZE_X);
}

//coordinate to index
int ctoi(int coordinate, int dir) {

	switch (dir) {
	case VARTICAL:   return ((coordinate - BOARD_SPOINT_Y) / TILE_PXSIZE_Y);
	case HORIZONTAL: return ((coordinate - BOARD_SPOINT_X) / TILE_PXSIZE_X);
	default:break;
	}
	return -1;
}

//y��index��0�ł��邩�Ȃ������m�F����֐�
bool check_yindex_min(int index) {

	return index < BOARD_SIZE_X;
}