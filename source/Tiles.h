#pragma once

//タイル
class Tile {

	//タイル値
	unsigned char value;
	/*
	0:定常青  5:横青    10:縦青    15:範囲青
	1:定常緑  6:横緑    11:縦緑    16:範囲緑
	2:定常黄  7:横黄    12:縦黄    17:範囲黄
	3:定常赤  8:横赤    13:縦赤    18:範囲赤
	4:定常紫  9:横紫    14:縦紫    19:範囲紫
	*/

	//グラフィックハンドル (DXLIB依存)
	static int ghandle[25];

	//グラフィックハンドル（アローイメージ）
	static int ahandle[3];

	//消去フレーム(0～25フレーム ※画像1枚5フレーム * 5枚)
	int vanish_frame = 0;

	//落下フレーム(12 * count フレーム)
	int fall_frame = 0;

public:

	//消去予約フラグ
	bool vanish = false;

	//グラフィックを読み込む((48[px],48[px])*5tiles*5tiles)(DXLIB依存)
	static void loadGraph(const char *fileName);

	//タイルの交換
	static void exchange(Tile &a, Tile &b);

	//初期化
	void setValue(const unsigned char Value);

	//値取得(0～4)
	int  getValueColor();

	//消去の時間を進める(true:完了　false:未完了)
	bool advanceVAnim();

	//クイック消去
	void quickVAnim();

	//消去時間をリセットする
	void resetVAnim();

	//消去時間を取得する
	int getVFrame();

	//消去状態を取得する(引数false:消去済みなら1，true:消去中なら1)
	int getVState(bool type = false);

	//落下時間を進める
	void advanceFAnim(int count);

	//落下時間をリセットする
	void resetFallFrame();

	//落下状態の取得
	int getFState();

	//落下完了状態を取得する(true:完了 false:未完了)
	bool getFFinished(int count);

	//タイプ取得(0:定常 1:横 2:縦 3:範囲)
	int  getValueType();

	//描画(vanish:破壊度(0～4))(DXLIB依存)
	void draw(const int& xPos, const int& yPos);
};