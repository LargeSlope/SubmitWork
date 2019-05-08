#pragma once
#include "../point1/point1.h"

//面座標型
template<class T>
class point2 {

	T point2<T>::arc() {

		return ((T)(atan((e.y - s.y)*1.0 / (e.x - s.x))));
	}

	template<class U>
	bool isin_x(point1<T> point, point2<U> line) {
		if ((((double)p2.s.x <= (double)p1.x && (double)p2.e.x >= (double)p1.x) ||
			((double)p2.e.x <= (double)p1.x && (double)p2.s.x >= (double)p1.x)) &&
			(((double)p2.s.y <= (double)p1.y && (double)p2.e.y >= (double)p1.y) ||
			((double)p2.e.y <= (double)p1.y && (double)p2.s.y >= (double)p1.y)))return true;
		else return false;
	}
public:
	point1<T> s, e;

	point2() {
		s = 0, e = 0;
	}
	point2(point1<T> point) {
		s = point, e = point;
	}
	point2(T sx, T sy, T ex, T ey) {
		s.x = sx, s.y = sy, e.x = ex, e.y = ey;
	}
	point2(point1<T> s, point1<T> e) {
		this->s = s, this->e = e;
	}
	point2(const point2<T> &point) {
		s = point.s, e = point.e;
	}

	point1<T> operator=(point1<T> a) {
		s = a, e = a;
		return a;
	}
	point1<T> operator[](int index) {
		switch (index) {
		case 0: return s;
		case 1: return point1<T>(e.x, s.y);
		case 2: return e;
		case 3: return point1<T>(s.x, e.y);
		default:return point1<T>(-1, -1);
		}
		return p;
	}
	T operator=(T a) {
		s = a, e = a;
		return a;
	}
	point2<T> operator+(point1<T> a) {
		return point2<T>(s + a, e + a);
	}
	point2<T> operator-(point1<T> a) {
		return point2<T>(s - a, e - a);
	}
	point2<T> operator+(point2<T> a) {
		return point2<T>(s + a.s, e + a.e);
	}
	point2<T> operator-(point2<T> a) {
		return point2<T>(s - a.s, e - a.e);
	}
	point2<T> operator*(T a) {
		return point2<T>(s * a, e * a);
	}
	point2<T> operator+(T a) {
		return point2<T>(s + a, e + a);
	}
	point2<T> operator-(T a) {
		return point2<T>(s - a, e - a);
	}

	point2<T> operator+=(point1<T> a) {
		s += a, e += a;
		return *this;
	}
	point2<T> operator-=(point1<T> a) {
		s -= a, e -= a;
		return *this;
	}
	point2<T> operator+=(point2<T> a) {
		s += a.s, e += a.e;
		return *this;
	}
	point2<T> operator-=(point2<T> a) {
		s -= a.s, e -= a.e;
		return *this;
	}
	point2<T> operator*=(T a) {
		s *= a.s, e *= a.e;
		return *this;
	}
	point2<T> operator+=(T a) {
		s += a.s, e += a.e;
		return *this;
	}
	point2<T> operator-=(T a) {
		s -= a.s, e -= a.e;
		return *this;
	}
	void operator()(T a, T b, T c, T d) {
		s = point1<T>(a, b);
		e = point1<T>(c, d);
	}

	operator point2<double>() const
	{
		return point2<double>((double)s.x, (double)s.y, (double)e.x, (double)e.y);
	}
	operator point2<float>() const
	{
		return point2<float>((float)s.x, (float)s.y, (float)e.x, (float)e.y);
	}
	operator point2<int>() const
	{
		return point2<int>((int)s.x, (int)s.y, (int)e.x, (int)e.y);
	}
	operator point2<short>() const
	{
		return point2<short>((short)s.x, (short)s.y, (short)e.x, (short)e.y);
	}

	//長さを取得
	double length() {
		return sqrt(pow((e.x - s.x), 2) + pow((e.y - s.y), 2));
	}

	//角度を取得
	double angle() {
		if (s.x <= e.x && s.y <= e.y) {

			return (arc());
		}
		if (s.x > e.x) {

			return (arc() + PI);
		}
		if (s.x <= e.x && s.y > e.y) {

			return (arc() + PI * 2);
		}

		return 0;
	}

	//ベクトルの取得
	point1<T> vec() {

		return point1<T>(e.x - s.x, e.y - s.y);
	}

	//法線ベクトルを取得
	point1<T> norm() {
		return point1<T>(s.y - e.y, e.x - s.x);
	}

	//交差点の座標
	point1<T> crossPoint(point2<T> line) {
		double
			l1 = ((e.y - s.y) * 1.0) / (e.x - s.x),
			l2 = ((line.e.y - line.s.y) * 1.0) / (line.e.x - line.s.x),
			c1 = ((-l1 * s.x) + s.y) * 1.0,
			c2 = ((-l2 * line.s.x) + line.s.y) * 1.0;

		if (l1 != l2) {

			return point1<T>((T)((c2 - c1) / (l1 - l2)), (T)(((c1 * l2) - (c2 * l1)) / (l2 - l1)));
		}
		return s;
	}

	//交差判定
	bool isec(point2<T> line) {
		point1<T> point = crossPoint(line);

		if (isin_x(point, *this) && isin_x(point, line)) {

			return true;
		}
		return false;
	}

	//矩形領域ごと移動
	void adjust(point1<T> point, int point_num) {
		point1<T> size(e.x - s.x, e.y - s.y);

		switch (point_num) {

		case BOTTOM:
			s = point1<T>(point.x - size.x / 2, point.y - size.y);
			e = point1<T>(point.x + size.x / 2, point.y);
			break;
		case LEFT:
			s = point1<T>(point.x, point.y - size.y / 2);
			e = point1<T>(point.x + size.x, point.y + size.y / 2);
			break;
		case RIGHT:
			s = point1<T>(point.x - size.x, point.y - size.y / 2);
			e = point1<T>(point.x, point.y + size.y / 2);
			break;
		case TOP:
			s = point1<T>(point.x - size.x / 2, point.y);
			e = point1<T>(point.x + size.x / 2, point.y + size.y);
			break;
		case LEFT & TOP:
			s = point1<T>(point.x, point.y);
			e = point1<T>(point.x + size.x, point.y + size.y);
			break;
		case RIGHT & TOP:
			s = point1<T>(point.x - size.x, point.y);
			e = point1<T>(point.x, point.y + size.y);
			break;
		case RIGHT & BOTTOM:
			s = point1<T>(point.x - size.x, point.y - size.y);
			e = point1<T>(point.x, point.y);
			break;
		case LEFT & BOTTOM:
			s = point1<T>(point.x, point.y - size.y);
			e = point1<T>(point.x + size.x, point.y);
			break;
		}
	}

	//s->e方向に対し点が左右どちらにあるのか(false:左 true:右)
	bool lorr(point1<T> point) {
		double ang = point2<T>((T)s.x, (T)s.y, (T)point.x, (T)point.y).angle() - (double)angle();

		if (ang >= 0. && ang < PI) {

			return true;
		}
		return false;
	}
};