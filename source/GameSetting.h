#pragma once
//�Q�[�����e�Ɋւ���Z�b�e�B���O���ڂł�

/* [lslib\higher\winfunc.h]
#define WINDOW_SIZE_X	(816)	//�E�B���h�E���T�C�Y[px]
#define WINDOW_SIZE_Y	(624)	//�E�B���h�E�c�T�C�Y[px]
*/

#define TILE_GRAPH_NUM (25)	//�^�C���摜�̑��������ł�("Resource\Image\tiles.png")
#define TILE_GRAPH_XNUM (5)	//�^�C���摜�̉�������(�F��)
#define TILE_GRAPH_YNUM (5)	//�^�C���摜�̏c������(�A�j���[�V�����t���[����)

#define TILE_PXSIZE_X (48)	//�^�C�������ς݉摜��1��������̉��T�C�Y[px]
#define TILE_PXSIZE_Y (48)	//�^�C�������ς݉摜��1��������̏c�T�C�Y[px]

#define BOARD_SIZE_NUM (200)	//10[tiles] * 20[tiles]
#define BOARD_SIZE_X (10)	//10[tiles]
#define BOARD_SIZE_Y (20)	//�㔼�̈� + �����̈� = 20[tile]

#define BOARD_SPOINT_X (168)	//(816-(48*10))/2
#define BOARD_SPOINT_Y (-408)	//(624-(48*10))/2 -(48*10)

#define BOARD_AREA point2<int>(168, 72, 648, 552)	//�}�E�X�ň�����͈�
#define BOARD_AREA2 point2<int>(168, 72, 600, 504)	//�}�E�X�ň�����͈�

#define BOARD_DRAW_POINT_X BOARD_SPOINT_X + (i % BOARD_SIZE_X) * TILE_PXSIZE_X
#define BOARD_DRAW_POINT_Y BOARD_SPOINT_Y + (i / BOARD_SIZE_X) * TILE_PXSIZE_Y

#define TILE_GRAPH_NAME "Resource/Image/tiles.png"
#define ARROW_GRAPH_NAME "Resource/Image/arrow.png"
#define BOARD_GRAPH_NAME "Resource/Image/board.png"
#define BOARD_GRAPH_NAME2 "Resource/Image/board2.png"
#define BOARD_GRAPH_NAME3 "Resource/Image/timeup.png"
#define RESULT_GRAPH_NAME "Resource/Image/result.png"
#define TITLE_GRAPH_NAME "Resource/Image/menu.png"

#define RESULT_HISCORE "score/score.txt"


#define VARTICAL	BOARD_SIZE_X	//�}�b�`���O����(�c)
#define HORIZONTAL	(1)	//�}�b�`���O����(��)

#define ANIM_DIM	2	//�A�j���[�V������2��ޑ���
#define VANISH	0	//��������
#define FALL	1	//��������

#define QUICK true	//�N�C�b�N���[�h��I��

#define VANISHING true
#define VANISHED false

#define ON true
#define OFF false

#define WINNUM (3)

#define TIME_MAX (30 * 60)	//���Ԑ���30[s]*60FPS
#define FTIME_MAX (3 * 60) //3[s]*60FPS
