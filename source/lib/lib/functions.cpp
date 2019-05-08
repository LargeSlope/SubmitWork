#include "functions.h"

//split関数 ( 文字列用 )
std::vector<std::string> split(std::string str, char c) {

	//バッファ
	std::string buff;

	//結果
	std::vector<std::string> result;

	//文字列の全領域を探索
	for (auto it = str.begin(); it != str.end(); it++) {

		//スプリッタ一致時
		if ((*it) == c || (*it) == '\n' || (*it) == '\0') {

			//バッファを結果に格納
			result.push_back( buff );
			buff = "";
		}
		//非一致時
		else {

			//バッファに追加
			buff += (*it);
		}
	}
	//結果
	return result;
}

//split関数 ( 数値用 )
std::vector<unsigned int> nsplit(std::string str, char c) {

	//バッファ
	std::string buff;

	//結果
	std::vector<unsigned int> result;

	//文字列の全領域を探索
	for (auto it = str.begin(); it != str.end(); it++) {

		//スプリッタ一致時
		if ((*it) == c || (*it) == '\n' || (*it) == '\0') {

			//バッファを結果に格納
			result.push_back((unsigned int)atoi(buff.c_str()));
			buff = "";
		}
		//非一致時
		else {

			//バッファに追加
			buff += (*it);
		}
	}
	//結果
	return result;
}

//targetをrad回転させる
template<class T>
point1<T> rot(point1<T> origin, point1<T> target, double rad) {

	point1<T> point = target - origin;

	return(
		point1<T>(
		(T)(cos(rad) * point.x - sin(rad) * point.y + origin.x),
			(T)(sin(rad) * point.x + cos(rad) * point.y + origin.y)
			));
}

//点と線分の距離を求める
float dis(point1<float> point, point2<float> line) {

	//点と点の距離
	float length_s = (float)point2<float>(point, line.s).length(),
		length_e = (float)point2<float>(point, line.e).length();

	//基本角度領域に変換
	point2<float> Hline = line - line.s;
	point1<float> Point = point - line.s;

	Hline = point2<float>(point1<float>(), rot(Hline.s, Hline.e, -line.angle()));
	Point = rot(point1<float>(), Point, -line.angle());


	//条件分岐
	if (Hline.s.x <= Point.x && Point.x <= Hline.e.x) {

		return (float)(((Point.y) >= 0) ? (Point.y) : -(Point.y));
	}
	else if (length_s < length_e) {

		return length_s;
	}
	else {

		return length_e;
	}
	return -1;
}

//lineを基準としたmoveの成分分解 ( s:平行 e:垂直 )
point2<float> getVector(point2<float> line, point2<float> move) {

	//物体の移動ベクトル
	point1<float> mvec = move.vec();

	//線のベクトル
	point1<float> lvec = line.vec();

	//結果
	return point2<float>(
		lvec * ((mvec * lvec) / pow(lvec.length(), 2.f)),
		mvec - lvec * ((mvec * lvec) / pow(lvec.length(), 2.f)));
}
