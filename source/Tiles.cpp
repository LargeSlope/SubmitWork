#include "Tiles.h"
#include "GameSetting.h"
#include "DxLib.h"

//�O���t�B�b�N�n���h��(DXLIB�ˑ�)
int Tile::ghandle[25] = { 0 };
//�O���t�B�b�N�n���h���i�A���[�C���[�W�j
int Tile::ahandle[3] = { 0 };

//�O���t�B�b�N��ǂݍ���(DXLIB�ˑ�)
void Tile::loadGraph(const char *fileName) {

	//�O���t�B�b�N�ǂݍ��݊֐�(DXLIB)
	LoadDivGraph(
		fileName,
		TILE_GRAPH_NUM,
		TILE_GRAPH_XNUM, TILE_GRAPH_YNUM,
		TILE_PXSIZE_X, TILE_PXSIZE_Y,
		ghandle);

	//�A���[�C���[�W�̓ǂݍ���
	LoadDivGraph(ARROW_GRAPH_NAME, 3, 3, 1, 48, 48, ahandle);
}

//�^�C���̌���
void Tile::exchange(Tile &a, Tile &b) {

	Tile buff = a;
	a = b, b = buff;
}

//������
void Tile::setValue(const unsigned char Value) {

	int rand = GetRand(100);
	value = Value;
	vanish_frame = 0;
	fall_frame = 0;
	vanish = false;

	if (rand < 97) {
		value += 0;	//�ʏ�(97%)
	}
	else if (rand < 98) {
		value += 5;	//��(1%)
	}
	else if (rand < 99) {
		value += 10;//�c(1%)
	}
	else {
		value += 15;//�͈�(1%)
	}
}

//�l�擾(0�`4)
int  Tile::getValueColor() {

	return (int)value % TILE_GRAPH_XNUM;
}

//�^�C�v�擾(0:��� 1:�� 2:�c 3:�͈�)
int  Tile::getValueType() {

	return (int)value / TILE_GRAPH_XNUM;
}

//�����̎��Ԃ�i�߂�(true:�����@false:������)
bool Tile::advanceVAnim() {

	if (vanish_frame < TILE_GRAPH_YNUM * 6) {

		vanish_frame++;
		return false;
	}
	else return true;
}

//�N�C�b�N����
void Tile::quickVAnim() {

	vanish_frame = TILE_GRAPH_YNUM * 6;
}

//�������Ԃ����Z�b�g����
void Tile::resetVAnim() {

	vanish_frame = 0;
}

//�������Ԃ��擾����
int Tile::getVFrame() {

	return vanish_frame;
}

//������Ԃ��擾����(����false:�����ς݂Ȃ�1�Ctrue:�������Ȃ�1)
int Tile::getVState(bool type) {

	if ((vanish_frame >= TILE_GRAPH_YNUM * 6) && type == false) return 1;
	else if ((0 < vanish_frame) && (vanish_frame < TILE_GRAPH_YNUM * 6) && type == true) return 1;
	return 0;
}

//�������Ԃ�i�߂�
void Tile::advanceFAnim(int count) {

	if (fall_frame < count * 12) fall_frame++;
}

//�������Ԃ����Z�b�g����
void Tile::resetFallFrame() {

	fall_frame = 0;
}

//������Ԃ̎擾
int Tile::getFState() {

	return fall_frame;
}

//����������Ԃ��擾����(true:���� false:������)
bool Tile::getFFinished(int count) {

	return (fall_frame >= count * 12) && count;
}

//�`��(DXLIB�ˑ�)
void Tile::draw(const int& xPos, const int& yPos) {

	//�O���t�B�b�N�ԍ�
	int graph_num = (value % TILE_GRAPH_XNUM) + (vanish_frame / TILE_GRAPH_XNUM) * TILE_GRAPH_XNUM;

	//��O����
	if (graph_num < 0 || 24 < graph_num) return;

	//�`��֐�(DXLIB)
	DrawGraph(xPos, yPos + fall_frame * 4, ghandle[graph_num], TRUE);

	//�^�C�v�̕\��
	if (getValueType()) DrawGraph(xPos, yPos + fall_frame * 4, ahandle[getValueType() - 1], TRUE);

	//test
	//DrawFormatString(xPos, yPos, 0x00, "%d", fall_frame);
}