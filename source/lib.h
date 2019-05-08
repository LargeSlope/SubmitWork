#pragma once

//ドラッグ中のインデックス取得
int getDragIndex();

//ドラッグ判定
bool drag();

//ドラッグ完了判定
bool fdrag();

//indexのリバース関数
int reverse(int index);

//coordinate to index (引数dir：VARTICAL X座標, HORIZONTAL Y座標)
int ctoi(int coordinate, int dir);

//yのindexが0であるかないかを確認する関数
bool check_yindex_min(int index);