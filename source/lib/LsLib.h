/*///////////////////////////////////////////////////////////////////////////////////////////////////
*【LSLIB共通機能】																					*
*	作成日：2019/1/26																				*
*	更新日：2019/1/26																				*
*	バージョン：1.0.0																				*
///////////////////////////////////////////////////////////////////////////////////////////////////*/

/* 共通ヘッダ========================================= */
#include "lib/common.h"

/* 高機能ヘッダ群===================================== */

//ウィンドウ標準機能
#ifdef WINFUNC
#include "higher/winfunc.h"
#endif

//入出力関連
#ifdef CINPUT
#include "higher/input.h"
#endif

//ファイル関連
#ifdef FILEIO
#include "higher/fileio.h"
#endif

//カメラ
#ifdef CAMERA
#include "higher/camera.h"
#endif

//GUI
#ifdef GUI
#include "higher/gui.h"
#endif