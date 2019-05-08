#include "lib.h"
#define CINPUT
#include "lib/LsLib.h"
#undef CINPUT
#include "GameSetting.h"

using namespace input;

//ƒhƒ‰ƒbƒO’†‚ÌƒCƒ“ƒfƒbƒNƒXæ“¾
int getDragIndex() {

	int index_x = (Input::mouse.s_point.x - BOARD_SPOINT_X) / TILE_PXSIZE_X;
	int index_y = (Input::mouse.s_point.y - BOARD_SPOINT_Y) / TILE_PXSIZE_Y;
	return (index_x + index_y * BOARD_SIZE_X);
}

//ƒhƒ‰ƒbƒO”»’è
bool drag() {

	//ƒhƒ‰ƒbƒO”ÍˆÍ“à‚Éƒhƒ‰ƒbƒOŠJnƒ|ƒCƒ“ƒg‚ª‘¶İ‚·‚é‚±‚Æ
	bool result1 = BOARD_AREA < Input::mouse.s_point;

	//ƒhƒ‰ƒbƒO’†‚Å‚ ‚é‚±‚Æ
	bool result2 = Input::mouse.push[0] > 0;

	return result1 && result2;
}

//ƒhƒ‰ƒbƒOŠ®—¹”»’è
bool fdrag() {

	//ƒhƒ‰ƒbƒO”ÍˆÍ“à‚Éƒhƒ‰ƒbƒOŠJnEI—¹ƒ|ƒCƒ“ƒg‚ª‘¶İ‚·‚é‚±‚Æ
	bool result1 = BOARD_AREA < Input::mouse.s_point;
	bool result2 = BOARD_AREA < Input::mouse.e_point;

	//ƒhƒ‰ƒbƒO‘€ì‚ªI—¹‚µ‚½‚±‚Æ
	bool result3 = Input::mouse.detach[LEFT];

	return (result1 && result2 && result3);
}

/*ƒŠƒo[ƒXŠÖ”‚É‚Â‚¢‚Ä*/
//‰º}‚Ì‚æ‚¤‚ÉC‰º‚©‚çã‚ÉŒü‚©‚Á‚Ä’Tõ‚·‚é‚æ‚¤Cindex‚Ì’è‹`‚ğ•ÏX‚µ‚Ü‚·D
//‰E‘¤‚©‚çC1—ñ’Tõ‚µI‚¦‚½‚çCŸ(¶)‚Ì—ñ‚ğ’Tõ‚µ‚Ü‚·D
//ZZZZZZZªªª
//ZZZZZZZªªª
//ZZZZZZZªªª
//ZZZZZZZªªª
//ZZZZZZZªªª
//ZZZZZZZªªª
//ZZZZZZZªªª
//ZZZZZZZªªª
//ZZZZZZZªªª
//ZZZZZZc‡B‡A‡@


//index‚ÌƒŠƒo[ƒXŠÖ”
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

//y‚Ìindex‚ª0‚Å‚ ‚é‚©‚È‚¢‚©‚ğŠm”F‚·‚éŠÖ”
bool check_yindex_min(int index) {

	return index < BOARD_SIZE_X;
}