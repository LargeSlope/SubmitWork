/*///////////////////////////////////////////////////////////////////////////////////////////////////
*�y�E�B���h�E�W�������z																				*
*	�쐬���F2019/1/26																				*
*	�X�V���F2019/1/26																				*
*	�o�[�W�����F1.0.0																				*
///////////////////////////////////////////////////////////////////////////////////////////////////*/
#include "winfunc.h"
#include "DxLib.h"

//�E�B���h�E�������֐��iDX���C�u�����ˑ��j
int Winit() {

	SetUseDirectDrawDeviceIndex(1);

	if (SetGraphMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, 16) != DX_CHANGESCREEN_OK) return 1;

	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK) return 2;

	if (SetBackgroundColor((WINDOW_COLOR & 0x00FF0000) >> 16, (WINDOW_COLOR & 0x0000FF00) >> 8, (WINDOW_COLOR & 0x000000FF))) return 3;

	if (DxLib_Init()) return 4; //DxLib������

	if (SetDrawScreen(DX_SCREEN_BACK)) return 5; //BackGround�`��

	return 0;
}

//�E�B���h�E�X�V�����iDX���C�u�����ˑ��j
int Wupdate(unsigned char update_flag) {

	//(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)

	return (
		(!(update_flag & 0x01) ? (ScreenFlip() == 0) : 1) &&
		(!(update_flag & 0x02) ? (ProcessMessage() == 0) : 1) &&
		(!(update_flag & 0x04) ? (ClearDrawScreen() == 0) : 1)
		);
}

//�v���Z�X�I��
void End() {

	DxLib_End(); // DX���C�u�����I������
}