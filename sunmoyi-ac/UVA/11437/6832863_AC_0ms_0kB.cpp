#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
};
typedef Point Vector;

double Sqr(double x) {
	return x * x;
}
double dcmp(double x) {
	if (fabs(x) < eps)
		return 0;
	return x < 0 ? -1 : 1;
}
Vector operator + (const Point& A, const Point& B) {
	return Vector(A.x + B.x, A.y + B.y);
}
Vector operator - (const Point& A, const Point& B) {
	return Vector(A.x - B.x, A.y - B.y);
}
Vector operator * (const Point& A, double a) {
	return Vector(A.x * a, A.y * a);
}
Vector operator / (const Point& A, double a) {
	return Vector(A.x / a, A.y / a);
}
double Cross(const Vector& A, const Vector& B) {
	return A.x * B.y - A.y * B.x;
}
double Dot(const Vector& A, const Vector& B) {
	return A.x * B.x + A.y * B.y;
}
double Length(const Vector& A) {
	return sqrt(Dot(A, A));
}
bool operator < (const Point& A, const Point& B) {
	return A.x < B.x || (A.x == B.x && A.y < B.y);
}
bool operator == (const Point& A, const Point& B) {
	return A.x == B.x && A.y == B.y;
}
//得到两直线交点 
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w) {
	Point u = P - Q;
	double t = Cross(w, u) / Cross(v, w);
	return P + v * t;
}
Point A, B, C, D, E, F;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
		Vector CF = Vector((B - C) + (A - B) * 2.0 / 3);
		Vector BE = Vector((A - B) + (C - A) * 2.0 / 3);
		Vector AD = Vector((C - A) + (B - C) * 2.0 / 3);
		Point P = GetLineIntersection(B, BE, A, AD);
		Point R = GetLineIntersection(C, CF, A, AD);
		Point Q = GetLineIntersection(B, BE, C, CF);
		double res = fabs(Cross(Q - P, R - P));
		printf("%lld\n", (long long)(res / 2.0 + 0.5));
	}
	return 0;
}