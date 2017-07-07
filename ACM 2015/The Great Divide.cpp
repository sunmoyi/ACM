#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <vector>  
#include <algorithm>  

using namespace std;
const double pi = 4 * atan(1);
const double eps = 1e-8;

inline int dcmp(double x) { if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1; }
inline double getDistance(double x, double y) { return sqrt(x * x + y * y); }

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	void read() { scanf("%lf%lf", &x, &y); }
	void write() { printf("%lf %lf", x, y); }

	bool operator == (const Point& u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0; }
	bool operator != (const Point& u) const { return !(*this == u); }
	bool operator < (const Point& u) const { return x < u.x || (x == u.x && y < u.y); }
	bool operator > (const Point& u) const { return u < *this; }
	bool operator <= (const Point& u) const { return *this < u || *this == u; }
	bool operator >= (const Point& u) const { return *this > u || *this == u; }
	Point operator + (const Point& u) { return Point(x + u.x, y + u.y); }
	Point operator - (const Point& u) { return Point(x - u.x, y - u.y); }
	Point operator * (const double u) { return Point(x * u, y * u); }
	Point operator / (const double u) { return Point(x / u, y / u); }
	double operator * (const Point& u) { return x*u.y - y*u.x; }
};

typedef Point Vector;

struct Line {
	double a, b, c;
	Line(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c) {}
};

struct Circle {
	Point o;
	double r;
	Circle() {}
	Circle(Point o, double r = 0) : o(o), r(r) {}
	void read() { o.read(), scanf("%lf", &r); }
	Point point(double rad) { return Point(o.x + cos(rad)*r, o.y + sin(rad)*r); }
	double getArea(double rad) { return rad * r * r / 2; }
};


namespace Punctual {
	double getDistance(Point a, Point b) { double x = a.x - b.x, y = a.y - b.y; return sqrt(x*x + y*y); }
};

namespace Vectorial {
	/* ���: ���������ȵĳ˻��ٳ������Ǽнǵ�����, �нǴ���90��ʱ���Ϊ�� */
	double getDot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }

	/* ���: ���������������ɵ��������������������, cross(v, w) = -cross(w, v) */
	double getCross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

	double getLength(Vector a) { return sqrt(getDot(a, a)); }
	double getPLength(Vector a) { return getDot(a, a); }
	double getAngle(Vector u) { return atan2(u.y, u.x); }
	double getAngle(Vector a, Vector b) { return acos(getDot(a, b) / getLength(a) / getLength(b)); }
	Vector rotate(Vector a, double rad) { return Vector(a.x*cos(rad) - a.y*sin(rad), a.x*sin(rad) + a.y*cos(rad)); }
	/* ��λ���� */
	Vector getNormal(Vector a) { double l = getLength(a); return Vector(-a.y / l, a.x / l); }
};

namespace Linear {
	using namespace Vectorial;

	Line getLine(double x1, double y1, double x2, double y2) { return Line(y2 - y1, x1 - x2, y1*x2 - x1*y2); }
	Line getLine(double a, double b, Point u) { return Line(a, -b, u.y * b - u.x * a); }
	//����ֱ�ߵĽ���
	bool getIntersection(Line p, Line q, Point& o) {
		if (fabs(p.a * q.b - q.a * p.b) < eps)
			return false;
		o.x = (q.c * p.b - p.c * q.b) / (p.a * q.b - q.a * p.b);
		o.y = (q.c * p.a - p.c * q.a) / (p.b * q.a - q.b * p.a);
		return true;
	}

	/* ֱ��pv��ֱ��qw�Ľ��� */
	bool getIntersection(Point p, Vector v, Point q, Vector w, Point& o) {
		if (dcmp(getCross(v, w)) == 0) return false;
		Vector u = p - q;
		double k = getCross(w, u) / getCross(v, w);
		o = p + v * k;
		return true;
	}

	/* ��p��ֱ��ab�ľ��� */
	double getDistanceToLine(Point p, Point a, Point b) { return fabs(getCross(b - a, p - a) / getLength(b - a)); }
	double getDistanceToSegment(Point p, Point a, Point b) {
		if (a == b) return getLength(p - a);
		Vector v1 = b - a, v2 = p - a, v3 = p - b;
		if (dcmp(getDot(v1, v2)) < 0) return getLength(v2);
		else if (dcmp(getDot(v1, v3)) > 0) return getLength(v3);
		else return fabs(getCross(v1, v2) / getLength(v1));
	}

	/* ��p��ֱ��ab�ϵ�ͶӰ */
	Point getPointToLine(Point p, Point a, Point b) { Vector v = b - a; return a + v*(getDot(v, p - a) / getDot(v, v)); }

	/* �ж��߶��Ƿ���ڽ��� */
	bool haveIntersection(Point a1, Point a2, Point b1, Point b2) {
		double c1 = getCross(a2 - a1, b1 - a1), c2 = getCross(a2 - a1, b2 - a1), c3 = getCross(b2 - b1, a1 - b1), c4 = getCross(b2 - b1, a2 - b1);
		return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
	}

	/* �жϵ��Ƿ����߶��� */
	bool onSegment(Point p, Point a, Point b) { return dcmp(getCross(a - p, b - p)) == 0 && dcmp(getDot(a - p, b - p)) < 0; }
}

namespace Triangular {
	using namespace Vectorial;

	double getAngle(double a, double b, double c) { return acos((a*a + b*b - c*c) / (2 * a*b)); }
	double getArea(double a, double b, double c) { double s = (a + b + c) / 2; return sqrt(s*(s - a)*(s - b)*(s - c)); }
	double getArea(double a, double h) { return a * h / 2; }
	double getArea(Point a, Point b, Point c) { return fabs(getCross(b - a, c - a)) / 2; }
	double getDirArea(Point a, Point b, Point c) { return getCross(b - a, c - a) / 2; }
};

namespace Polygonal {
	using namespace Vectorial;
	using namespace Linear;
	//͹����� ����p��͹������ n�Ǽ���Ԫ�ظ���
	double getArea(Point* p, int n) {
		double ret = 0;
		for (int i = 1; i < n - 1; i++)
			ret += getCross(p[i] - p[0], p[i + 1] - p[0]);
		return fabs(ret) / 2;
	}

	/* ͹�� */
	int getConvexHull(Point* p, int n, Point* ch) {
		sort(p, p + n);
		int m = 0;
		for (int i = 0; i < n; i++) {
			/* �ɹ��� */
			//while (m > 1 && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-1])) < 0) m--;  
			while (m > 1 && dcmp(getCross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 1])) <= 0) m--;
			ch[m++] = p[i];
		}
		int k = m;
		for (int i = n - 2; i >= 0; i--) {
			/* �ɹ��� */
			//while (m > k && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) < 0) m--;  
			while (m > k && dcmp(getCross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0) m--;
			ch[m++] = p[i];
		}
		if (n > 1) m--;
		return m;
	}
	//��o�ǲ�����͹����p�� ����p��Ԫ�ظ���Ϊn
	int isPointInPolygon(Point o, Point* p, int n) {
		int wn = 0;
		for (int i = 0; i < n; i++) {
			int j = (i + 1) % n;
			if (onSegment(o, p[i], p[j])) return 0; // �߽���  
			int k = dcmp(getCross(p[j] - p[i], o - p[i]));
			int d1 = dcmp(p[i].y - o.y);
			int d2 = dcmp(p[j].y - o.y);
			if (k > 0 && d1 <= 0 && d2 > 0) wn++;
			if (k < 0 && d2 <= 0 && d1 > 0) wn--;
		}
		return wn ? -1 : 1;
	}
};

namespace Circular {
	using namespace Linear;
	using namespace Vectorial;
	using namespace Triangular;

	/* ֱ�ߺ�ԭ�Ľ��� */
	int getLineCircleIntersection(Point p, Point q, Circle O, double& t1, double& t2, vector<Point>& sol) {
		Vector v = q - p;
		/* ʹ��ǰ�����sol */
		//sol.clear();  
		double a = v.x, b = p.x - O.o.x, c = v.y, d = p.y - O.o.y;
		double e = a*a + c*c, f = 2 * (a*b + c*d), g = b*b + d*d - O.r*O.r;
		double delta = f*f - 4 * e*g;
		if (dcmp(delta) < 0) return 0;
		if (dcmp(delta) == 0) {
			t1 = t2 = -f / (2 * e);
			sol.push_back(p + v * t1);
			return 1;
		}

		t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(p + v * t1);
		t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(p + v * t2);
		return 2;
	}

	/* Բ��Բ�Ľ��� */
	int getCircleCircleIntersection(Circle o1, Circle o2, vector<Point>& sol) {
		double d = getLength(o1.o - o2.o);

		if (dcmp(d) == 0) {
			if (dcmp(o1.r - o2.r) == 0) return -1;
			return 0;
		}

		if (dcmp(o1.r + o2.r - d) < 0) return 0;
		if (dcmp(fabs(o1.r - o2.r) - d) > 0) return 0;

		double a = getAngle(o2.o - o1.o);
		double da = acos((o1.r*o1.r + d*d - o2.r*o2.r) / (2 * o1.r*d));

		Point p1 = o1.point(a - da), p2 = o1.point(a + da);

		sol.push_back(p1);
		if (p1 == p2) return 1;
		sol.push_back(p2);
		return 2;
	}

	/* ��������Բ������ */
	int getTangents(Point p, Circle o, Vector* v) {
		Vector u = o.o - p;
		double d = getLength(u);
		if (d < o.r) return 0;
		else if (dcmp(d - o.r) == 0) {
			v[0] = rotate(u, pi / 2);
			return 1;
		}
		else {
			double ang = asin(o.r / d);
			v[0] = rotate(u, -ang);
			v[1] = rotate(u, ang);
			return 2;
		}
	}

	/* a[i] �� b[i] �ֱ��ǵ�i��������O1��O2�ϵ��е� */
	int getTangents(Circle o1, Circle o2, Point* a, Point* b) {
		int cnt = 0;
		if (o1.r < o2.r) { swap(o1, o2); swap(a, b); }
		double d2 = getLength(o1.o - o2.o); d2 = d2 * d2;
		double rdif = o1.r - o2.r, rsum = o1.r + o2.r;
		if (d2 < rdif * rdif) return 0;
		if (dcmp(d2) == 0 && dcmp(o1.r - o2.r) == 0) return -1;

		double base = getAngle(o2.o - o1.o);
		if (dcmp(d2 - rdif * rdif) == 0) {
			a[cnt] = o1.point(base); b[cnt] = o2.point(base); cnt++;
			return cnt;
		}

		double ang = acos((o1.r - o2.r) / sqrt(d2));
		a[cnt] = o1.point(base + ang); b[cnt] = o2.point(base + ang); cnt++;
		a[cnt] = o1.point(base - ang); b[cnt] = o2.point(base - ang); cnt++;

		if (dcmp(d2 - rsum * rsum) == 0) {
			a[cnt] = o1.point(base); b[cnt] = o2.point(base); cnt++;
		}
		else if (d2 > rsum * rsum) {
			double ang = acos((o1.r + o2.r) / sqrt(d2));
			a[cnt] = o1.point(base + ang); b[cnt] = o2.point(base + ang); cnt++;
			a[cnt] = o1.point(base - ang); b[cnt] = o2.point(base - ang); cnt++;
		}
		return cnt;
	}

	/* ����ȷ������Բ */
	Circle CircumscribedCircle(Point p1, Point p2, Point p3) {
		double Bx = p2.x - p1.x, By = p2.y - p1.y;
		double Cx = p3.x - p1.x, Cy = p3.y - p1.y;
		double D = 2 * (Bx * Cy - By * Cx);
		double cx = (Cy * (Bx * Bx + By * By) - By * (Cx * Cx + Cy * Cy)) / D + p1.x;
		double cy = (Bx * (Cx * Cx + Cy * Cy) - Cx * (Bx * Bx + By * By)) / D + p1.y;
		Point p = Point(cx, cy);
		return Circle(p, getLength(p1 - p));
	}

	/* ����ȷ������Բ */
	Circle InscribedCircle(Point p1, Point p2, Point p3) {
		double a = getLength(p2 - p3);
		double b = getLength(p3 - p1);
		double c = getLength(p1 - p2);
		Point p = (p1 * a + p2 * b + p3 * c) / (a + b + c);
		return Circle(p, getDistanceToLine(p, p1, p2));
	}

	/* ������һ����ΪԲ�� */
	double getPublicAreaToTriangle(Circle O, Point a, Point b) {
		if (dcmp((a - O.o)*(b - O.o)) == 0) return 0;
		int sig = 1;
		double da = getPLength(O.o - a), db = getPLength(O.o - b);
		if (dcmp(da - db) > 0) {
			swap(da, db);
			swap(a, b);
			sig = -1;
		}

		double t1, t2;
		vector<Point> sol;
		int n = getLineCircleIntersection(a, b, O, t1, t2, sol);

		if (dcmp(da - O.r*O.r) <= 0) {
			if (dcmp(db - O.r*O.r) <= 0)   return getDirArea(O.o, a, b) * sig;

			int k = 0;
			if (getPLength(sol[0] - b) > getPLength(sol[1] - b)) k = 1;

			double ret = getArea(O.o, a, sol[k]) + O.getArea(getAngle(sol[k] - O.o, b - O.o));
			double tmp = (a - O.o)*(b - O.o);
			return ret * sig * dcmp(tmp);
		}

		double d = getDistanceToSegment(O.o, a, b);
		if (dcmp(d - O.r) >= 0) {
			double ret = O.getArea(getAngle(a - O.o, b - O.o));
			double tmp = (a - O.o)*(b - O.o);
			return ret * sig * dcmp(tmp);
		}


		double k1 = O.r / getLength(a - O.o), k2 = O.r / getLength(b - O.o);
		Point p = O.o + (a - O.o) * k1, q = O.o + (b - O.o) * k2;
		double ret1 = O.getArea(getAngle(p - O.o, q - O.o));
		double ret2 = O.getArea(getAngle(sol[0] - O.o, sol[1] - O.o)) - getArea(O.o, sol[0], sol[1]);
		double ret = (ret1 - ret2), tmp = (a - O.o)*(b - O.o);
		return ret * sig * dcmp(tmp);
	}

	double getPublicAreaToPolygon(Circle O, Point* p, int n) {
		if (dcmp(O.r) == 0) return 0;
		double area = 0;
		for (int i = 0; i < n; i++) {
			int u = (i + 1) % n;
			area += getPublicAreaToTriangle(O, p[i], p[u]);
		}
		return fabs(area);
	}
};

using namespace Vectorial;
using namespace Polygonal;

const int maxn = 505;

int N, M;
Point P[maxn], A[maxn], B[maxn];

bool judge() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			if (haveIntersection(A[i], A[i + 1], B[j], B[j + 1]))
				return false;
	}
	for (int i = 0; i < N; i++)
		if (isPointInPolygon(A[i], B, M) <= 0)
			return false;
	for (int i = 0; i < M; i++)
		if (isPointInPolygon(B[i], A, N) <= 0)
			return false;
	return true;
}

int main() {
	while (scanf("%d%d", &N, &M) == 2 && N + M) {
		for (int i = 0; i < N; i++)
			P[i].read();
		N = getConvexHull(P, N, A);
		for (int i = 0; i < M; i++) 
			P[i].read();
		M = getConvexHull(P, M, B);
		A[N] = A[0], B[M] = B[0];

		printf("%s\n", judge() ? "Yes" : "No");
	}
	return 0;
}