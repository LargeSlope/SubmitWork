#include "TileMng.h"
#define CINPUT
#include "lib/LsLib.h"
#undef CINPUT
#include "lib.h"
#include "GameSetting.h"

//�`��ʒu�i�萔�łȂ����߁C�����Œ�`���Ă���܂��j
#define DRAW_TILE_POINT_X	(BOARD_SPOINT_X + (i % BOARD_SIZE_X) * TILE_PXSIZE_X)
#define DRAW_TILE_POINT_Y	(BOARD_SPOINT_Y + (i / BOARD_SIZE_X) * TILE_PXSIZE_Y)

using namespace input;

//�^�C������
Tile TileMng::tile[BOARD_SIZE_NUM] = {};

//�X�R�A
int TileMng::score = 0;

//�N�C�b�N���[�h
bool TileMng::quick = true;

//�^�C���̏�����
void TileMng::init() {

	//�O���t�ǂݍ���
	Tile::loadGraph(TILE_GRAPH_NAME);

	//�X�R�A�̃��Z�b�g
	score = 0;

	//�^�C���̒l�Z�b�g
	for (int i = 0; i < BOARD_SIZE_NUM; i++) {

		tile[i].setValue(GetRand(TILE_GRAPH_XNUM - 1));
	}
}

//�`��(�h���b�O�ȊO)
int TileMng::_draw() {

	int drag_index = getDragIndex();

	for (int i = 0; i < BOARD_SIZE_NUM; i++) {

		if (i == drag_index && drag()) continue;

		tile[i].draw(DRAW_TILE_POINT_X, DRAW_TILE_POINT_Y);
	}

	return drag_index;
}

//�`��(�h���b�O����)
void TileMng::draw() {

	//�h���b�O���̃C���f�b�N�X
	int drag_index = _draw();

	//�h���b�O���̃^�C����`��
	if (drag()) tile[drag_index].draw(Input::mouse.point.x - 24, Input::mouse.point.y - 24);
}

//�X�V
int TileMng::update() {

	//�h���b�O�ɂ�����
	exchange();

	//�}�b�`3�����s����
	match3();

	//�����\��^�C������������
	vanish();

	//�^�C���̗���
	fall();

	//�^�C���̕�U
	fill();

	//�X�R�A��ԋp
	return score;
}

//�h���b�O�ɂ�����
void TileMng::exchange() {
	if (!fdrag()) return;	//�͈͓��ł̃h���b�O�@���@�h���b�O�������������Ɓ@������
	int sindex_x = ctoi(Input::mouse.s_point.x, HORIZONTAL),
		sindex_y = ctoi(Input::mouse.s_point.y, VARTICAL);
	int eindex_x = ctoi(Input::mouse.e_point.x, HORIZONTAL),
		eindex_y = ctoi(Input::mouse.e_point.y, VARTICAL);

	//�ד��m�ȊO�̌������֎~����
	if (ABS((sindex_x + sindex_y * BOARD_SIZE_X) - (eindex_x + eindex_y * BOARD_SIZE_X)) != 1 &&
		ABS((sindex_x + sindex_y * BOARD_SIZE_X) - (eindex_x + eindex_y * BOARD_SIZE_X)) != 10  ||
		(sindex_x == 0 && eindex_x == 9) || (sindex_x == 9 && eindex_x == 0)) return;

	Tile::exchange(tile[sindex_x + sindex_y * BOARD_SIZE_X], tile[eindex_x + eindex_y * BOARD_SIZE_X]);
}

//����
void TileMng::vanish() {

	for (int i = 0; i < BOARD_SIZE_NUM; i++) {

		//�ʏ탂�[�h��
		if (tile[i].vanish && !quick) {

			//�A�j���[�V�������s
			if (tile[i].advanceVAnim()) {

				//�A�j���[�V����������C�����\��t���O��OFF�ɂ���
				tile[i].vanish = false;

				//�X�R�A�̉��Z
				score += 10;
			}
		}
		//�N�C�b�N���[�h��
		else if (tile[i].vanish) {

			tile[i].quickVAnim();
			tile[i].vanish = false;
		}
	}
}

//�}�b�`3�p�����ς݃`�F�b�N(true:�������܂��͏����ς݂̃^�C��������)
bool TileMng::checkVanish(int index1, int index2, int index3) {

	if (tile[index1].getVState(VANISHED) ||
		tile[index2].getVState(VANISHED) ||
		tile[index3].getVState(VANISHED) ||
		tile[index1].getVState(VANISHING) ||
		tile[index2].getVState(VANISHING) ||
		tile[index3].getVState(VANISHING)) return true;
	return false;
}

//1�s����
void TileMng::vanishLine(int index) {

	//�s�ԍ��擾
	int lnum = index / BOARD_SIZE_X;

	//�ꊇ����
	for (int i = 0; i < BOARD_SIZE_X; i++) {

		tile[lnum * VARTICAL + i].vanish = true;
	}
}

//1�����
void TileMng::vanishRow(int index) {

	//��ԍ��擾
	int rnum = index % BOARD_SIZE_X;

	//�ꊇ����
	for (int i = BOARD_SIZE_Y / 2; i < BOARD_SIZE_Y; i++) {

		tile[rnum + VARTICAL * i].vanish = true;
	}
}

//�͈͏���
void TileMng::vanishSq(int index) {

	//�͂ݏo���h�~(index�̈ʒu���[�ɑ��݂���Ƃ��̃t���O)
	bool top = !(index / BOARD_SIZE_X),
		right = !(index % BOARD_SIZE_X - 9),
		bottom = !(index / BOARD_SIZE_X - 19),
		left = !(index % BOARD_SIZE_X);

	if (!top && !left)		tile[index + (-11)].vanish = true;
	if (!top)				tile[index + (-10)].vanish = true;
	if (!top && !right)		tile[index + (-9)].vanish = true;
	if (!left)				tile[index + (-1)].vanish = true;
	if (!right)				tile[index + (+1)].vanish = true;
	if (!bottom && !left)	tile[index + (+9)].vanish = true;
	if (!bottom)			tile[index + (+10)].vanish = true;
	if (!bottom && !right)	tile[index + (+11)].vanish = true;
}

//����^�C���̏���
void TileMng::vanishSpecial() {
	for (int i = BOARD_SIZE_NUM / 2; i < BOARD_SIZE_NUM; i++) {
		if (!tile[i].vanish) continue;
		switch (tile[i].getValueType()) {
		case 1: vanishLine(i); break;
		case 2: vanishRow(i); break;
		case 3: vanishSq(i); break;
		default: break;
		}
	}
}

//�}�b�`3(�����w��)
void TileMng::_match3(int index, int dir) {

	int color0 = tile[index + dir * 0].getValueColor(),
		color1 = tile[index + dir * 1].getValueColor(),
		color2 = tile[index + dir * 2].getValueColor();

	//�������̃^�C���Ƃ̓}�b�`���O���Ȃ�
	if (checkVanish(index + dir * 0, index + dir * 1, index + dir * 2)) return;

	//�S�Ă̐F����v���Cvanish�t���O��true�ɂ���
	if ((color0 == color1) && (color1 == color2)) {

		tile[index + dir * 0].vanish = true;
		tile[index + dir * 1].vanish = true;
		tile[index + dir * 2].vanish = true;
	}
}

//�}�b�`3
void TileMng::match3() {

	//�}�b�`���O(�����̈�)
	for (int i = BOARD_SIZE_NUM / 2; i < BOARD_SIZE_NUM - 2; i++) {

		if ((i / BOARD_SIZE_X) < (BOARD_SIZE_Y - 2)) _match3(i, VARTICAL);	//�c�}�b�`���O
		if ((i % BOARD_SIZE_X) < (BOARD_SIZE_X - 2)) _match3(i, HORIZONTAL); //���}�b�`���O
	}

	//����^�C��������
	vanishSpecial();
}

//�����ɂ�����
void TileMng::fexchange(int index1, int count) {

	int index2 = index1 + (count * VARTICAL);
	if (index2 >= BOARD_SIZE_NUM) return; //��O�����iout of range�j

	tile[index1].resetFallFrame();
	tile[index2].resetFallFrame();
	Tile::exchange(tile[index1], tile[index2]);
}

//����
void TileMng::fall() {

	int count = 0; //��^�C���J�E���^

	for (int i = 0; i < BOARD_SIZE_NUM; i++) {

		//�t�c�T��
		int index = reverse(i);

		//��^�C���Ȃ�΃J�E���g�A�b�v
		if (tile[index].getVState()) { count++;
		
			//�ŏ㕔����^�C���Ȃ�΃J�E���^���Z�b�g
			if (index < VARTICAL) count = 0; continue;
		}

		//�����������ɁC�^�C��������
		if (tile[index].getFFinished(count)) fexchange(index, count);

		//�^�C���𗎉�������A�j���[�V����
		else if(!quick) tile[index].advanceFAnim(count);

		//�N�C�b�N����
		else if(count) fexchange(index, count);

		//�ŏ㕔�̎��̓J�E���^�����Z�b�g����
		if (index < VARTICAL) count = 0;
	}
}

//�����Ԃ��擾(�߂�ltrue:���� false:�s����)
bool TileMng::stable() {

	bool result = false;

	match3();

	for (int i = 0; i < BOARD_SIZE_NUM; i++) {

		result |= tile[i].vanish | (bool)tile[i].getFState();
	}
	return !result;
}

//��U
void TileMng::fill() {

	for (int i = 0; i < BOARD_SIZE_NUM / 2; i++) {

		if (tile[i].getVState()) {

			tile[i].setValue(GetRand(TILE_GRAPH_XNUM - 1));
			tile[i].resetVAnim();
		}
	}
}