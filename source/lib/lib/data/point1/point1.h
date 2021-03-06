#pragma once

/* ¤èQ¤============================================================================================= */
//âÎl
#define ABS(num) ((num) < 0 ? -(num) : (num))
//~ü¦
#define PI (3.14159265359)
/* ¢èQ¢============================================================================================= */

//_ÀW^
template<class T>
class point1 {

	//ØèÌÄ(val:üÍl lvl:ØèÌÄ(¬_Èº))
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

	//]u
	point1<T> reverse() { return point1<T>(y, x); }

	//xNgÌ·³ðæ¾
	T length() { return ( T ) sqrt( pow( x, (T)2 ) + pow( y, (T)2 ) ); }

	//TCY²®(xNgÌ·³ðsizeÉ·é)
	point1<T> resize(T size) { return (*this / length()) * size; }
};
