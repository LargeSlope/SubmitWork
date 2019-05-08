#pragma once

/* ▽定数群▽============================================================================================= */
//絶対値
#define ABS(num) ((num) < 0 ? -(num) : (num))
//円周率
#define PI (3.14159265359)
/* △定数群△============================================================================================= */

//点座標型
template<class T>
class point1 {

	//桁切り捨て(val:入力値 lvl:切り捨て桁(小数点以下))
	T afloor(T val, int lvl) {

		return (T)floor(val * (T)pow(10, lvl)) / (T)pow(10, lvl);
	}

public:
	T x = 0, y = 0;

	point1() {
		x = 0;
		y = 0;
	}
	point1(T a) {
		x = a;
		y = a;
	}
	point1(T a, T b) {
		x = a;
		y = b;
	}
	point1(const point1<T>& point) {
		x = point.x;
		y = point.y;
	}

	point1<T> operator+(point1<T> a) { return point1<T>(x + a.x, y + a.y); }
	point1<T> operator-(point1 a) { return point1<T>(x - a.x, y - a.y); }
	point1<T> operator+(T a) { return point1<T>(x + a, y + a); }
	point1<T> operator-(T a) { return point1<T>(x - a, y - a); }
	point1<T> operator*(T a) { return point1<T>(x * a, y * a); }
	point1<T> operator/(T a) { return point1<T>(x / a, y / a); }
	T operator*(point1<T> a) { return x * a.x + y * a.y; }
	T operator=(T a) { x = a, y = a; return a; }
	bool operator==(point1<T> a) { return (x == a.x && y == a.y); }

	point1<T> operator+=(point1<T> a) { return *this = *this + a; }
	point1<T> operator-=(point1<T> a) { return *this = *this - a; }
	point1<T> operator+=(T a) { return *this = *this + a; }
	point1<T> operator-=(T a) { return *this = *this - a; }
	point1<T> operator*=(T a) { return *this = *this * a; }
	point1<T> operator/=(T a) { return *this = *this / a; }
	void operator()(T a, T b) { x = a, y = b; }

	operator point1<double>() const {
		return point1<double>((double)x, (double)y);
	}
	operator point1<float>() const {
		return point1<float>((float)x, (float)y);
	}
	operator point1<int>() const {
		return point1<int>((int)x, (int)y);
	}
	operator point1<short>() const {
		return point1<short>((short)x, (short)y);
	}

	//転置
	point1<T> reverse() { return point1<T>(y, x); }

	//ベクトルの長さを取得
	T length() { return ( T ) sqrt( pow( x, (T)2 ) + pow( y, (T)2 ) ); }

	//サイズ調整(ベクトルの長さをsizeにする)
	point1<T> resize(T size) { return (*this / length()) * size; }
};
