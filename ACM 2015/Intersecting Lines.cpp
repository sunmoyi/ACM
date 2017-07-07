#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define PI acos(-1.0)
#define TWO_PI 2 * acos(-1.0)
const double eps = 1e-6;

double dcmp(double x) {
	if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) { }
};

typedef Point Vector;

Vector operator + (const Vector& A, const Vector& B) {
	return Vector(A.x + B.x, A.y + B.y);
}
Vector operator - (const Point& A, const Point& B) {
	return Vector(A.x - B.x, A.y - B.y);
}

Vector operator * (const Vector& A, double p) {
	return Vector(A.x*p, A.y*p);
}

Vector operator / (const Vector& A, double p) {
	return Vector(A.x / p, A.y / p);
}

double Dot(const Vector& A, const Vector& B) {
	return A.x*B.x + A.y*B.y;
}

double Length(const Vector& A) {
	return sqrt(Dot(A, A));
}

//����A, B�н�
double Angle(const Vector& A, const Vector& B) {
	return acos(Dot(A, B) / Length(A) / Length(B));
}
//���
double Cross(const Vector& A, const Vector& B) {
	return A.x*B.y - A.y*B.x;
}
//���


bool operator < (const Point& p1, const Point& p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

bool operator == (const Point& p1, const Point& p2) {
	return p1.x == p2.x && p1.y == p2.y;
}

Vector Normal(Vector A) {
	double L = Length(A);
	return Vector(-A.y / L, A.x / L);
}

//��ֱ�߽���
Point GetLineIntersection(const Point& A, const Point& B, const Point& C, const Point& D) {
	double a1 = A.y - B.y;
	double b1 = B.x - A.x;
	double c1 = A.x*B.y - B.x*A.y;

	double a2 = C.y - D.y;
	double b2 = D.x - C.x;
	double c2 = C.x*D.y - D.x*C.y;

	double x = (b1*c2 - b2*c1) / (a1*b2 - a2*b1);
	double y = (a2*c1 - a1*c2) / (a1*b2 - a2*b1);

	return Point(x, y);
}

//����ֱ���ϵ�ͶӰ
Point GetLineProjection(Point P, Point A, Point B) {
	Vector v = B - A;
	return A + v*(Dot(v, P - A) / Dot(v, v));
}

//����A ��ʱ����תrad��
Vector Rotate(const Vector& A, double rad) {
	return Vector(A.x*cos(rad) - A.y*sin(rad), A.x*sin(rad) + A.y*cos(rad));
}
//�淶�ཻ
bool SegmentProperIntersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
	double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
		c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
	return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}

bool OnSegment(const Point& p, const Point& a1, const Point& a2) {
	return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

bool SegmentIntersects(Point a1, Point a2, Point b1, Point b2)
{
	double c1 = Cross(a2 - a1, b1 - a1);
	double c2 = Cross(a2 - a1, b2 - a1);
	double c3 = Cross(b2 - b1, a1 - b1);
	double c4 = Cross(b2 - b1, a2 - b1);
	if (dcmp(c1)*dcmp(c2) == 0 && dcmp(c3)*dcmp(c4) == 0)
	{
		if (OnSegment(a1, b1, b2) || OnSegment(a2, b1, b2) || a1 == b1 || a2 == b1)
			return true;
		else
			return false;
	}
	return dcmp(c1)*dcmp(c2) <= 0 && dcmp(c3)*dcmp(c4) <= 0;
}

//�㵽ֱ�ߵľ���
double DistanceToSegment(const Point& P, const Point& A, const Point& B) {
	if (A == B) return Length(P - A);
	Vector v1 = B - A, v2 = P - A, v3 = P - B;
	if (dcmp(Dot(v1, v2)) < 0) return Length(v2);
	else if (dcmp(Dot(v1, v3)) > 0) return Length(v3);
	else return fabs(Cross(v1, v2)) / Length(v1); // �����ȡ����ֵ���õ������������
}

// �㼯͹��
// �����ϣ����͹���ı���������㣬������ <= �ĳ� <
// ���������㼯���޸ģ����Ըĳɴ�������
vector<Point> ConvexHull(vector<Point> p) {
	// Ԥ����ɾ���ظ���
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());

	int n = p.size();
	int m = 0;
	vector<Point> ch(n + 1);
	for (int i = 0; i < n; i++) {
		while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--) {
		while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = p[i];
	}
	if (n > 1) m--;
	ch.resize(m);
	return ch;
}
//��p�Ƿ���͹���ڲ�
int IsPointInPolygon(const Point& p, const vector<Point>& poly) {
	int wn = 0;
	int n = poly.size();
	for (int i = 0; i < n; i++) {
		const Point& p1 = poly[i];
		const Point& p2 = poly[(i + 1) % n];
		if (p1 == p || p2 == p || OnSegment(p, p1, p2)) return -1; // �ڱ߽���
		int k = dcmp(Cross(p2 - p1, p - p1));
		int d1 = dcmp(p1.y - p.y);
		int d2 = dcmp(p2.y - p.y);
		if (k > 0 && d1 <= 0 && d2 > 0) wn++;
		if (k < 0 && d2 <= 0 && d1 > 0) wn--;
	}
	if (wn != 0) return 1; // �ڲ�
	return 0; // �ⲿ
}

//����͹���Ƿ��ཻ
bool ConvexPolygonDisjoint(const vector<Point> ch1, const vector<Point> ch2) {
	int c1 = ch1.size();
	int c2 = ch2.size();
	for (int i = 0; i < c1; i++)
		if (IsPointInPolygon(ch1[i], ch2) != 0) return false; // �ڲ���߽���
	for (int i = 0; i < c2; i++)
		if (IsPointInPolygon(ch2[i], ch1) != 0) return false; // �ڲ���߽���
	for (int i = 0; i < c1; i++)
		for (int j = 0; j < c2; j++)
			if (SegmentProperIntersection(ch1[i], ch1[(i + 1) % c1], ch2[j], ch2[(j + 1) % c2])) return false;
	return true;
}

// ����ε��������
double PolygonArea(vector<Point> p) {
	double area = 0;
	int n = p.size();
	for (int i = 1; i < n - 1; i++)
		area += Cross(p[i] - p[0], p[i + 1] - p[0]);
	return area / 2;
}

int Dist2(const Point& A, const Point& B) {
	return (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y);
}


// ���ص㼯ֱ����ƽ��
int diameter2(vector<Point>& points) {
	vector<Point> p = ConvexHull(points);
	int n = p.size();
	if (n == 1) return 0;
	if (n == 2) return Dist2(p[0], p[1]);
	p.push_back(p[0]); // ���ȡģ
	int ans = 0;
	for (int u = 0, v = 1; u < n; u++) {
		// һ��ֱ����ס��p[u]-p[u+1]
		for (;;) {
			// ��Area(p[u], p[u+1], p[v+1]) <= Area(p[u], p[u+1], p[v])ʱֹͣ��ת
			// ��Cross(p[u+1]-p[u], p[v+1]-p[u]) - Cross(p[u+1]-p[u], p[v]-p[u]) <= 0
			// ����Cross(A,B) - Cross(A,C) = Cross(A,B-C)
			// �����Cross(p[u+1]-p[u], p[v+1]-p[v]) <= 0
			int diff = Cross(p[u + 1] - p[u], p[v + 1] - p[v]);
			if (diff <= 0) {
				ans = max(ans, Dist2(p[u], p[v])); // u��v�Ƕ����
				if (diff == 0) ans = max(ans, Dist2(p[u], p[v + 1])); // diff == 0ʱu��v+1Ҳ�Ƕ����
				break;
			}
			v = (v + 1) % n;
		}
	}
	return ans;
}

// ������p1, p2��ֱ��һ�㷽��ax+by+c=0
// (x2-x1)(y-y1) = (y2-y1)(x-x1)
//�㵽ֱ�ߵľ���fabs(a*x + b*y + c) / sqrt(a*a + b*b)
void getLineGeneralEquation(const Point& p1, const Point& p2, double& a, double& b, double &c) {
	a = p2.y - p1.y;
	b = p1.x - p2.x;
	c = -a*p1.x - b*p1.y;
}

/********************************************************************************************/
bool iszero(double x)
{
	return fabs(x) < eps;
}

double Crossleft(Point A, Point B, Point C)
{
	return (B.x - A.x) * (C.y - A.y) - (B.y - A.y)*(C.x - A.x);
}

//��p1�ٵ㼯p��
int InPolygon(Point p1, int n, Point *p)
{
	const int offset = 1000;
	int cnt, i = 0;
	Point p2;
	p[n] = p[0];
	while (i < n)
	{
		p2.x = rand() + offset;
		p2.y = rand() + offset;
		for (i = cnt = 0; i < n; i++)
		{
			if (iszero(Crossleft(p1, p[i], p[i + 1])) &&
				(p[i].x - p1.x) * (p[i + 1].x - p1.x) < eps &&
				(p[i].y - p1.y) * (p[i + 1].y - p1.y) < eps)
				return true;
			else if (iszero(Crossleft(p1, p2, p[i])))
				break;
			else if (Crossleft(p[i], p[i + 1], p1) * Crossleft(p[i], p2, p[i + 1]) > eps  &&
				Crossleft(p1, p2, p[i + 1]) * Crossleft(p1, p[i], p2) > eps)
				cnt++;
		}
	}
	return cnt & 1;
}
/**********************************************************************************************/

double angle(Vector v)
{
	return atan2(v.y, v.x);
}

struct Line {
	Point P;
	Vector v;
	double ang; // ���ǣ�����x��������ת������v����Ҫ�Ľǣ����ȣ�
	Line() {}
	Line(Point p, Vector v) :P(p), v(v) { ang = atan2(v.y, v.x); }
	Point point(double t) {
		return P + v*t;
	}
	Line move(double d) {
		return Line(P + Normal(v)*d, v);
	}
	bool operator < (const Line& L) const {
		return ang < L.ang;
	}
};

struct LineB {
	Point a, b;
	LineB(Point A, Point B) :a(A), b(B) {}
	LineB() {}
};

struct Circle {
	Point c;
	double r;
	Circle(Point c, double r) :c(c), r(r) {}
	Point point(double a) {
		return Point(c.x + cos(a)*r, c.y + sin(a)*r);
	}
};


//ֱ��L��ԲC�Ĺ�ϵt1��t2��ʾ�е��λ��
int getLineCircleIntersection(Line L, Circle C, double& t1, double& t2, vector<Point>& sol)
{
	double a = L.v.x, b = L.P.x - C.c.x, c = L.v.y, d = L.P.y - C.c.y;
	double e = a*a + c*c, f = 2 * (a*b + c*d), g = b*b + d*d - C.r*C.r;
	double delta = f*f - 4 * e*g; // �б�ʽ
	if (dcmp(delta) < 0)
		return 0; // ����
	if (dcmp(delta) == 0)
	{ // ����
		t1 = t2 = -f / (2 * e);
		sol.push_back(L.point(t1));
		return 1;
	}
	// �ཻ
	t1 = (-f - sqrt(delta)) / (2 * e);
	sol.push_back(L.point(t1));
	t2 = (-f + sqrt(delta)) / (2 * e);
	sol.push_back(L.point(t2));
	return 2;
}

//��Բc1 & c2 �Ľ�����뵽sol vector ��  ע�����vector�����㣬 ��������ֵn����ǰn���Ǵ�
int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol) {
	double d = Length(C1.c - C2.c);
	if (dcmp(d) == 0)
	{
		if (dcmp(C1.r - C2.r) == 0)
			return -1; // �غϣ�����ཻ��
		return 0;
	}
	if (dcmp(C1.r + C2.r - d) < 0)
		return 0;
	if (dcmp(fabs(C1.r - C2.r) - d) > 0)
		return 0;

	double a = angle(C2.c - C1.c);
	double da = acos((C1.r*C1.r + d*d - C2.r*C2.r) / (2 * C1.r*d));
	Point p1 = C1.point(a - da), p2 = C1.point(a + da);

	sol.push_back(p1);
	if (p1 == p2)
		return 1;
	sol.push_back(p2);
	return 2;
}

double NormalizeAngle(double rad, double center = PI) {
	return rad - TWO_PI * floor((rad + PI - center) / TWO_PI);
}
// ���������Բ1�ļ��Ǳ�����rad��
void getCircleCircleIntersection(Point c1, double r1, Point c2, double r2, vector<double>& rad) {
	double d = Length(c1 - c2);
	if (dcmp(d) == 0) return; // �������ں������غϣ������ཻ
	if (dcmp(r1 + r2 - d) < 0) return;
	if (dcmp(fabs(r1 - r2) - d) > 0) return;

	double a = angle(c2 - c1);
	double da = acos((r1*r1 + d*d - r2*r2) / (2 * r1*d));
	rad.push_back(NormalizeAngle(a - da));
	rad.push_back(NormalizeAngle(a + da));
}

//�����������Բ
Circle CircumscribedCircle(Point p1, Point p2, Point p3) {
	double Bx = p2.x - p1.x, By = p2.y - p1.y;
	double Cx = p3.x - p1.x, Cy = p3.y - p1.y;
	double D = 2 * (Bx*Cy - By*Cx);
	double cx = (Cy*(Bx*Bx + By*By) - By*(Cx*Cx + Cy*Cy)) / D + p1.x;
	double cy = (Bx*(Cx*Cx + Cy*Cy) - Cx*(Bx*Bx + By*By)) / D + p1.y;
	Point p = Point(cx, cy);
	return Circle(p, Length(p1 - p));
}

//���������ڽ�Բ
Circle InscribedCircle(Point p1, Point p2, Point p3) {
	double a = Length(p2 - p3);
	double b = Length(p3 - p1);
	double c = Length(p1 - p2);
	Point p = (p1*a + p2*b + p3*c) / (a + b + c);
	return Circle(p, DistanceToSegment(p, p1, p2));
}

//����Բ��Բ��Point(xc, yc), �뾶r  �����(xp, yp)����������
// ����p��ԲC�����ߡ�v[i]�ǵ�i�����ߵ�������������������
int getTangents(Point p, Circle C, Vector* v) {
	Vector u = C.c - p;
	double dist = Length(u);
	if (dist < C.r)
		return 0;
	else if (dcmp(dist - C.r) == 0)
	{ // p��Բ�ϣ�ֻ��һ������
		v[0] = Rotate(u, PI / 2);
		return 1;
	}
	else
	{
		double ang = asin(C.r / dist);
		v[0] = Rotate(u, -ang);
		v[1] = Rotate(u, +ang);
		return 2;
	}
}

Point GetLineIntersection(const Line& a, const Line& b) {
	Vector u = a.P - b.P;
	double t = Cross(b.v, u) / Cross(a.v, b.v);
	return a.P + a.v*t;
}

//�����(xp, yp)�뾶Ϊr  �������(x1, y1)&&��(x2, y2)�����ɵ�ֱ�����е�԰
vector<Point> CircleThroughPointTangentToLineGivenRadius(Point p, Line L, double r)
{
	vector<Point> ans;
	double t1, t2;
	getLineCircleIntersection(L.move(-r), Circle(p, r), t1, t2, ans);
	getLineCircleIntersection(L.move(r), Circle(p, r), t1, t2, ans);
	return ans;
}

//����ֱ�ߣ�(x1,y1),(x2,y2)����ֱ�ߣ�(x3, y3),(x4, y4)������  �Ұ뾶Ϊr��Բ
vector<Point> CircleTangentToLinesGivenRadius(Line a, Line b, double r)
{
	vector<Point> ans;
	Line L1 = a.move(-r), L2 = a.move(r);
	Line L3 = b.move(-r), L4 = b.move(r);
	ans.push_back(GetLineIntersection(L1, L3));
	ans.push_back(GetLineIntersection(L1, L4));
	ans.push_back(GetLineIntersection(L2, L3));
	ans.push_back(GetLineIntersection(L2, L4));
	return ans;
}

//����Բ��(x1,y1),r1����Բ��(x2,y2), r2������������Բ�����в��Ұ뾶Ϊr��Բ
vector<Point> CircleTangentToTwoDisjointCirclesWithRadius(Circle c1, Circle c2, double r) {
	vector<Point> ans;
	Vector v = c2.c - c1.c;
	double dist = Length(v);
	int d = dcmp(dist - c1.r - c2.r - r * 2);
	if (d > 0)
		return ans;
	getCircleCircleIntersection(Circle(c1.c, c1.r + r), Circle(c2.c, c2.r + r), ans);
	return ans;
}

// ��p������ֱ��L����ߣ����ϲ��㣩
bool OnLeft(const Line& L, const Point& p) {
	return Cross(L.v, p - L.P) > 0;
}

// ��ֱ�߽��㣬�ٶ�����Ωһ����

const double INF = 1e8;

// ��ƽ�潻������
vector<Point> HalfplaneIntersection(vector<Line> L) {
	int n = L.size();
	sort(L.begin(), L.end()); // ����������

	int first, last;         // ˫�˶��еĵ�һ��Ԫ�غ����һ��Ԫ�ص��±�
	vector<Point> p(n);      // p[i]Ϊq[i]��q[i+1]�Ľ���
	vector<Line> q(n);       // ˫�˶���
	vector<Point> ans;       // ���

	q[first = last = 0] = L[0];  // ˫�˶��г�ʼ��Ϊֻ��һ����ƽ��L[0]
	for (int i = 1; i < n; i++) {
		while (first < last && !OnLeft(L[i], p[last - 1])) last--;
		while (first < last && !OnLeft(L[i], p[first])) first++;
		q[++last] = L[i];
		if (fabs(Cross(q[last].v, q[last - 1].v)) < eps) { // ������ƽ����ͬ��ȡ�ڲ��һ��
			last--;
			if (OnLeft(q[last], L[i].P)) q[last] = L[i];
		}
		if (first < last) p[last - 1] = GetLineIntersection(q[last - 1], q[last]);
	}
	while (first < last && !OnLeft(q[first], p[last - 1])) last--; // ɾ������ƽ��
	if (last - first <= 1) return ans; // �ռ�
	p[last] = GetLineIntersection(q[last], q[first]); // ������β������ƽ��Ľ���

													  // ��deque���Ƶ������
	for (int i = first; i <= last; i++) ans.push_back(p[i]);
	return ans;
}

LineB line[110];
int n;

/********************************************************************************************/
double Multi(Point p1, Point p2, Point p0) {
	return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

bool Check(LineB B) {
	if (fabs(B.a.x - B.b.x) < eps && fabs(B.a.y - B.b.y) < eps) return false;
	for (int i = 0; i < n; i++)
		if (Multi(line[i].a, B.b, B.a) * Multi(line[i].b, B.b, B.a) > eps) return false;
	return true;
}
/*******************************************************************************************/

Point p1, p2, p3, p4;
int N;

int main(void)
{
	while (scanf("%d", &N) != EOF)
	{
		printf("INTERSECTING LINES OUTPUT\n");
		for (int i = 1; i <= N; i++)
		{
			scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y);
			if (Crossleft(p1, p2, p3) == 0 && Crossleft(p1, p2, p4) == 0)
				printf("LINE\n");
			else if((p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y)*(p3.x - p4.x) == 0)
					printf("NONE\n");
			else
			{
				Point p0 = GetLineIntersection(p1, p2, p3, p4);
				printf("POINT %.2f %.2f\n", p0.x, p0.y);
			}
		}
		printf("END OF OUTPUT\n");
	}
	return 0;
}