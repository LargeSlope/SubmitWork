#pragma once

//�h���b�O���̃C���f�b�N�X�擾
int getDragIndex();

//�h���b�O����
bool drag();

//�h���b�O��������
bool fdrag();

//index�̃��o�[�X�֐�
int reverse(int index);

//coordinate to index (����dir�FVARTICAL X���W, HORIZONTAL Y���W)
int ctoi(int coordinate, int dir);

//y��index��0�ł��邩�Ȃ������m�F����֐�
bool check_yindex_min(int index);