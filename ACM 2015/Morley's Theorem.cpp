#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

struct point {
	double x, y;
	point(double x = 0, double y = 0) :x(x), y(y) {}
};

typedef point vector;

vector operator +(vector a, vector b)
{
	return vector(a.x + b.x, a.y + b.y);
}

vector operator - (point a, point b)
{
	return vector(a.x - b.x, a.y - b.y);
}

vector operator * (vector a, double k)
{
	return vector(k * a.x, k * a.y);
}

vector operator /(vector a, double k)
{
	return vector(a.x / k, a.y / k);
}

double dot(vector a, vector b)
{
	return a.x * b.x + a.y * b.y;
}

double lenth(vector &a)
{
	return sqrt(dot(a, a));
}

double angle(vector a, vector b)
{
	return acos(dot(a, b) / lenth(a) / lenth(b));
}

double cross(vector a, vector b)
{
	return a.x * b.y - b.x * a.y;
}

double area(point a, point b, point c)
{
	return cross(b - a, c - a);
}
//向量a沿着逆时针方向旋转rad  （弧度制）
vector rotate(vector a, double rad)
{
	return vector(a.x * cos(rad) - a.y * sin(rad), a.x* sin(rad) + a.y * cos(rad));
}

point getlineintersection(point p, vector v, point q, vector w)
{
	vector u = p - q;
	double t = cross(w, u) / cross(v, w);
	return p + v * t;
}

point getD(point a, point b, point c)
{
	vector v1 = c - b;
	double a1 = angle(a - b, v1);
	v1 = rotate(v1, a1 / 3);

	vector v2 = b - c;
	double a2 = angle(a - c, v2);
	v2 = rotate(v2, -a2 / 3);

	return getlineintersection(b, v1, c, v2);
}

int main(void)
{
	int T;
	point A, B, C, D, E, F;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf %lf %lf %lf %lf %lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
		D = getD(A, B, C);
		E = getD(B, C, A);
		F = getD(C, A, B);
		printf("%lf %lf %lf %lf %lf %lf\n", D.x, D.y, E.x, E.y, F.x, F.y);
	}
	return 0;
}