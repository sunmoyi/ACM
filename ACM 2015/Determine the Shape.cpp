#include<cstdio>  
#include<cmath>  
#include<algorithm>  
using namespace std;
const int MAXN = 300 + 10;

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) { }

};
typedef Point Vector;
Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (const Point& A, const Point& B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator * (const Vector& A, double p) { return Vector(A.x*p, A.y*p); }
double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }
double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }
Point a, b, c, d;
void print(int ans)
{
	switch (ans)
	{
	case 0:puts("Ordinary Quadrilateral"); break;
	case 1:puts("Trapezium"); break;
	case 2:puts("Parallelogram"); break;
	case 3:puts("Rhombus"); break;
	case 4:puts("Rectangle"); break;
	case 5:puts("Square"); break;
	}
}

int solve(Point a, Point b, Point c, Point d)
{
	int ans = 0;
	Vector ab = b - a, bc = c - b, cd = d - c, da = a - d;
	if (Cross(ab, cd) == 0 || Cross(da, bc) == 0)
		ans = 1;
	if (Cross(ab, cd) == 0 && Cross(da, bc) == 0)
	{
		ans = 2;
		if (Dot(c - a, b - d) == 0)
			ans = 3;
		if (Dot(ab, bc) == 0)
			ans = 4;
		if (Dot(c - a, b - d) == 0 && Dot(ab, bc) == 0)
			ans = 5;
	}
	return ans;
}

int main(void)
{
	int T, icase = 1;
	scanf("%d", &T);
	for (icase = 1; icase <= T; icase++)
	{
		Point a, b, c, d;
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
		int ans = 0;
		ans = max(ans, solve(a, b, c, d));
		ans = max(ans, solve(a, c, b, d));
		ans = max(ans, solve(a, b, d, c));

		printf("Case %d: ", icase);
		print(ans);
	}
	return 0;
}