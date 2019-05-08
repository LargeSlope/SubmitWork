#pragma once
/*///////////////////////////////////////////////////////////////////////////////////////////////////
*【ファイル標準入出力】																				*
*	作成日：2019/1/26																				*
*	更新日：2019/1/26																				*
*	バージョン：1.0.0																				*
///////////////////////////////////////////////////////////////////////////////////////////////////*/

/* 共通ヘッダファイル */
#include "../lib/common.h"

/* 動的配列 */
#include <vector>

/* 【名前空間】ノードデータ型 */
namespace fileio {

	/* リニア型 */
	class PointLinear {

	public:

		//リニアノード
		std::vector<point1<unsigned int>> node;

		//保存
		void save(char *filename);

		//読み込み
		void load(char *filename);
	};

	/* ポリゴン型 */
	class PointPolygon {

	public:

		//ポリゴンノード
		std::vector<point1<unsigned int>> node;

		//保存
		void save(char *filename);

		//読み込み
		void load(char *filename);
	};

	/* 分割ポリゴン型 */
	class DividePolygon {

	public:

		//ポリゴンノード
		std::vector<point1<unsigned int>> node;

		//保存
		void save(char *filename);

		//読み込み
		void load(char *filename);
	};
}