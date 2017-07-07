#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define esp 1e-6
#define PI acos(-1.0)
#define maxn 60

using namespace std;

int doublecmp(double x)
{
	if (fabs(x) < esp)
		return 0;
	else
		return x < 0 ? -1 : 1;
}

double torad(double deg)
{
	return deg / 180 * PI;
}

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) {}
};

typedef Point Vector;

Vector operator -(const Vector&A, const Vector&B)
{
	return Vector(A.x - B.x, A.y - B.y);
}

Vector operator + (const Vector&A, const Vector&B)
{
	return Vector(A.x + B.x, A.y + B.y);
}

Vector operator * (const Vector&A, double k)
{
	return Vector(A.x * k, A.y * k);
}

Vector operator / (const Vector&A, double k)
{
	return Vector(A.x / k, A.y / k);
}

bool operator < (const Point&A, const Point&B)
{
	return A.x < B.x || (A.x == B.x && A.y < B.y);
}

bool operator == (const Point&A, const Point&B)
{
	return doublecmp(A.x - B.x) == 0 && doublecmp(A.y - B.y) == 0;
}

Point read_point()
{
	double x, y;
	scanf("%lf %lf", &x, &y);
	return Point(x, y);
}

double dot(const Vector&A, const Vector&B)
{
	return A.x * B.x + A.y * B.y;
}

double cross(const Vector&A, const Vector&B)
{
	return A.x * B.y - B.x * A.y;
}

double lenth(const Vector&A)
{
	return sqrt(dot(A, A));
}

double distancetosegments(const Point&P, const Point&A, const Point&B)
{
	if (A == B)
		return lenth(P - A);
	Vector v1 = B - A, v2 = P - A, v3 = P - B;
	if (doublecmp(dot(v1, v2)) < 0)
		return lenth(v2);
	else if (doublecmp(dot(v1, v3)) > 0)
		return lenth(v3);
	else
		return fabs(cross(v1, v2)) / lenth(v1);
}

int T, A, B;
Point P[maxn], Q[maxn];
double Min, Max;

void update(Point P, Point A, Point B)
{
	Min = min(Min, distancetosegments(P, A, B));
	Max = max(Max, lenth(P - A));
	Max = max(Max, lenth(P - B));
}

int main(void)
{
	scanf("%d", &T);
	for (int icase = 1; icase <= T; icase++)
	{
		scanf("%d %d", &A, &B);
		for (int i = 0; i < A; i++)
			P[i] = read_point();
		for (int i = 0; i < B; i++)
			Q[i] = read_point();

		double Lena = 0, Lenb = 0;
		for (int i = 0; i < A - 1; i++)
			Lena += lenth(P[i + 1] - P[i]);
		for (int i = 0; i < B - 1; i++)
			Lenb += lenth(Q[i + 1] - Q[i]);

		int sa = 0, sb = 0;
		Point Pa = P[0], Pb = Q[0];
		Min = 1e9, Max = -1e9;
		while (sa < A - 1 && sb < B - 1)
		{
			double La = lenth(P[sa + 1] - Pa); // 甲到下一拐点的距离
			double Lb = lenth(Q[sb + 1] - Pb); // 乙到下一拐点的距离
			double T = min(La / Lena, Lb / Lenb); // 取合适的单位，可以让甲和乙的速度分别是LenA和LenB
			Vector Va = (P[sa + 1] - Pa) / La  *  T*Lena; // 甲的位移向量
			Vector Vb = (Q[sb + 1] - Pb) / Lb  *  T*Lenb; // 乙的位移向量
			update(Pa, Pb, Pb + Vb - Va); // 求解“简化版”，更新最小最大距离
			Pa = Pa + Va;
			Pb = Pb + Vb;
			if (Pa == P[sa + 1]) 
				sa++;
			if (Pb == Q[sb + 1]) 
				sb++;
		}
		printf("Case %d: %.0lf\n", icase, Max - Min);
	}
}