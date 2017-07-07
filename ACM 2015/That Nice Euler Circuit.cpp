#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define esp 1e-6

using namespace std;

int doublecmp(double x)
{ 
	if (fabs(x) < esp)
		return 0;
	if (x < 0)
		return -1;
	else
		return 1;
}

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) {}
};
typedef Point Vector;

Vector operator + (const Vector&A, const Vector&B)
{
	return Vector(A.x + B.x, A.y + B.y);
}

Vector operator - (const Vector&A, const Vector&B)
{
	return Vector(A.x - B.x, A.y - B.y);
}

Vector operator * (const Vector&A, double k)
{
	return Vector(k * A.x, k * A.y);
}

bool operator < (const Point&A, const Point&B)
{
	return A.x < B.x || (A.x == B.x && A.y < B.y);
}

bool operator == (const Point&A, const Point&B)
{
	return doublecmp(A.x - B.x) == 0 && doublecmp(A.y - B.y) == 0;
}

double dot(const Vector&A, const Vector&B)
{
	return A.x * B.x + A.y * B.y;
}

double cross(const Vector&A, const Vector&B)
{
	return A.x * B.y - B.x * A.y;
}
//求V, W线段的交点     P是线段V的起始点 V是V的方向向量
Point getlineintersection(const Point&P, const Vector&V, const Point&Q, const Vector&W)
{
	Vector u = P - Q;
	double t = cross(W, u) / cross(V, W);
	return P + V * t;
}
//线段规范相交
bool segmentproperintersection(const Point&a1, const Point&a2, const Point&b1, const Point&b2)
{
	double c1 = cross(a2 - a1, b1 - a1);
	double c2 = cross(a2 - a1, b2 - a1);
	double c3 = cross(b2 - b1, a1 - b1);
	double c4 = cross(b2 - b1, a2 - b1);
	return doublecmp(c1) * doublecmp(c2) < 0 && doublecmp(c3) * doublecmp(c4) < 0;
}
//点p在线段a1, a2中 已经排除在a1, a2端点的这种情况
bool onesegment(const Point&p, const Point&a1, const Point&a2)
{
	return doublecmp(cross(a1 - p, a2 - p)) == 0 && doublecmp(dot(a1 - p, a2 - p)) < 0;
}

const int maxn = 300 + 10;;
Point P[maxn], V[maxn * maxn];

int main(void)
{
	int n, icase = 0;
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lf %lf", &P[i].x, &P[i].y);
			V[i] = P[i];
		}
		n--;
		int c = n, e = n;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (segmentproperintersection(P[i], P[i + 1], P[j], P[j + 1]))
					V[c++] = getlineintersection(P[i], P[i + 1] - P[i], P[j], P[j + 1] - P[j]);
			}
		}
		sort(V, V + c);
		c = unique(V, V + c) - V;
		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (onesegment(V[i], P[j], P[j + 1]))
					e++;
			}
		}
		printf("Case %d: There are %d pieces.\n", ++icase, e + 2 - c);
	}
	return 0;
}