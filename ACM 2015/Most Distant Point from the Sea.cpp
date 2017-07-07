#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define PI acos(-1.0)
#define eps 1e-7
#define INF 0x3f3f3f3f

using namespace std;

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y){}
};

typedef Point Vector;

Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (const Point& A, const Point& B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator * (const Vector& A, double p) { return Vector(A.x*p, A.y*p); }
double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }
double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }
double Length(const Vector& A) { return sqrt(Dot(A, A)); }
Vector Normal(const Vector& A) { double L = Length(A); return Vector(-A.y / L, A.x / L); }

double PolygonArea(vector<Point> p) {
	int n = p.size();
	double area = 0;
	for (int i = 1; i < n - 1; i++)
		area += Cross(p[i] - p[0], p[i + 1] - p[0]);
	return area / 2;
}

struct Line {
	Point P;
	Vector v;
	double ang;
	Line() {}
	Line(Point P, Vector v) :P(P), v(v) { ang = atan2(v.y, v.x); }
	bool operator < (const Line& L) const 
	{
		return ang < L.ang;
	}
};

bool onleft(const Line&L, const Point&P)
{
	return Cross(L.v, P - L.P) > 0;
}

Point getlineitersection(const Line&a, const Line&b)
{
	Vector u = a.P - b.P;
	double t = Cross(b.v, u) / Cross(a.v, b.v);
	return a.P + a.v * t;
}

vector<Point> HalfplaneIntersection(vector<Line> L) {
	int n = L.size();
	sort(L.begin(), L.end()); // ����������

	int first, last;         // ˫�˶��еĵ�һ��Ԫ�غ����һ��Ԫ�ص��±�
	vector<Point> p(n);      // p[i]Ϊq[i]��q[i+1]�Ľ���
	vector<Line> q(n);       // ˫�˶���
	vector<Point> ans;       // ���

	q[first = last = 0] = L[0];  // ˫�˶��г�ʼ��Ϊֻ��һ����ƽ��L[0]
	for (int i = 1; i < n; i++) {
		while (first < last && !onleft(L[i], p[last - 1])) last--;
		while (first < last && !onleft(L[i], p[first])) first++;
		q[++last] = L[i];
		if (fabs(Cross(q[last].v, q[last - 1].v)) < eps) { // ������ƽ����ͬ��ȡ�ڲ��һ��
			last--;
			if (onleft(q[last], L[i].P)) q[last] = L[i];
		}
		if (first < last) p[last - 1] = getlineitersection(q[last - 1], q[last]);
	}
	while (first < last && !onleft(q[first], p[last - 1])) last--; // ɾ������ƽ��
	if (last - first <= 1) return ans; // �ռ�
	p[last] = getlineitersection(q[last], q[first]); // ������β������ƽ��Ľ���

													  // ��deque���Ƶ������
	for (int i = first; i <= last; i++) ans.push_back(p[i]);
	return ans;
}

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		vector<Vector>p, v, normal;

		int m, x, y;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &x, &y);
			p.push_back(Point(x, y));
		}

		if (PolygonArea(p) < 0)
			reverse(p.begin(), p.end());

		for (int i = 0; i < n; i++)
		{
			v.push_back(p[(i + 1) % n] - p[i]);
			normal.push_back(Normal(v[i]));
		}

		double left = 0, right = 100000;
		while (right - left > eps)
		{
			vector<Line>L;
			double mid = left + (right - left) / 2;
			for (int i = 0; i < n; i++)
				L.push_back(Line(p[i] + normal[i] * mid, v[i]));
			vector<Point>poly = HalfplaneIntersection(L);
			if (poly.empty())
				right = mid;
			else
				left = mid;
		}
		printf("%.6lf\n", left);
	}
	return 0;
}