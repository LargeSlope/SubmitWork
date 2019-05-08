/*///////////////////////////////////////////////////////////////////////////////////////////////////
*【ファイル標準入出力実装】																			*
*	作成日：2019/1/26																				*
*	更新日：2019/1/26																				*
*	バージョン：1.0.0																				*
///////////////////////////////////////////////////////////////////////////////////////////////////*/
#include "fileio.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace fileio;

//保存
void PointLinear::save(char *filename) {

	//ファイルストリーム
	std::ofstream ofs;

	//ファイルオープン
	ofs.open(filename, std::ios::out);

	//データの格納
	for (auto it = node.begin(); it != node.end(); it++) {

		//文字列に追加
		ofs << ((*it).x) << "," << ((*it).y) << std::endl;
	}

	//ファイルクローズ
	ofs.close();
}

//読み込み
void PointLinear::load(char *filename) {

	//ファイルストリーム
	std::ifstream ifs;

	//ファイル1行読み込みバッファ
	std::string line;

	//ファイルオープン
	ifs.open(filename, std::ios::in);

	//データの取得
	while (std::getline(ifs, line)) {

		//stringをpoint1型にパース
		node.push_back(point1<unsigned int>());
	}

	//ファイルクローズ
	ifs.close();
}

//保存
void PointPolygon::save(char *filename) {


}

//読み込み
void PointPolygon::load(char *filename) {


}

//保存
void DividePolygon::save(char *filename) {


}

//読み込み
void DividePolygon::load(char *filename) {


}