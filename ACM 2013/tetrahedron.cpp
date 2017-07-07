#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const double eps = 1e-6;

struct point
{
	double x, y, z;
} a[10];

struct V
{
	point st;
	point end;
};

point Cross(point a, point b)
{
	point s;
	s.x = a.y*b.z - a.z*b.y;
	s.y = a.z*b.x - a.x*b.z;
	s.z = a.x*b.y - b.x*a.y;
	return s;
}

double dot(point a, point b)
{
	double s = a.x*b.x + a.y*b.y + a.z*b.z;
	return s;
}

int main()
{
	while (cin >> a[1].x >> a[1].y >> a[1].z)
	{
		for (int i = 2; i <= 4; i++)
			cin >> a[i].x >> a[i].y >> a[i].z;
		//求平面方程 A*x + B*y + C*z + D = 0
		double A = ((a[2].y - a[1].y)*(a[3].z - a[1].z) - (a[2].z - a[1].z)*(a[3].y - a[1].y));
		double B = ((a[2].z - a[1].z)*(a[3].x - a[1].x) - (a[2].x - a[1].x)*(a[3].z - a[1].z));
		double C = ((a[2].x - a[1].x)*(a[3].y - a[1].y) - (a[2].y - a[1].y)*(a[3].x - a[1].x));
		double D = -(A * a[1].x + B * a[1].y + C * a[1].z);
		//cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
		double ret = A*a[4].x + B*a[4].y + a[4].z*C + D;
		if (fabs(ret) < eps)
		{
			puts("O O O O");
			continue;
		}
		V AB, AC, BC, AD, BD, CD;
		AB.st = a[1], AB.end = a[2];
		AC.st = a[1], AC.end = a[3];
		BC.st = a[2], BC.end = a[3];
		AD.st = a[1], AD.end = a[4];
		BD.st = a[2], BD.end = a[4];
		CD.st = a[3], CD.end = a[4];
		double aa = sqrt((AB.st.x - AB.end.x)*(AB.st.x - AB.end.x) + (AB.st.y - AB.end.y)*(AB.st.y - AB.end.y) +
			(AB.st.z - AB.end.z)*(AB.st.z - AB.end.z));
		double b = sqrt((AC.st.x - AC.end.x)*(AC.st.x - AC.end.x) + (AC.st.y - AC.end.y)*(AC.st.y - AC.end.y) +
			(AC.st.z - AC.end.z)*(AC.st.z - AC.end.z));
		double c = sqrt((BC.st.x - BC.end.x)*(BC.st.x - BC.end.x) + (BC.st.y - BC.end.y)*(BC.st.y - BC.end.y) +
			(BC.st.z - BC.end.z)*(BC.st.z - BC.end.z));
		double d = sqrt((AD.st.x - AD.end.x)*(AD.st.x - AD.end.x) + (AD.st.y - AD.end.y)*(AD.st.y - AD.end.y) +
			(AD.st.z - AD.end.z)*(AD.st.z - AD.end.z));
		double e = sqrt((BD.st.x - BD.end.x)*(BD.st.x - BD.end.x) + (BD.st.y - BD.end.y)*(BD.st.y - BD.end.y) +
			(BD.st.z - BD.end.z)*(BD.st.z - BD.end.z));
		double f = sqrt((CD.st.x - CD.end.x)*(CD.st.x - CD.end.x) + (CD.st.y - CD.end.y)*(CD.st.y - CD.end.y) +
			(CD.st.z - CD.end.z)*(CD.st.z - CD.end.z));
		double s1 = 0.5*(aa + b + c);
		double Sabc = sqrt(s1*(s1 - aa)*(s1 - b)*(s1 - c));
		double s2 = 0.5*(aa + e + d);
		double Sabd = sqrt(s2*(s2 - aa)*(s2 - e)*(s2 - d));
		double s3 = 0.5*(d + b + f);
		double Sacd = sqrt(s3*(s3 - d)*(s3 - b)*(s3 - f));
		double s4 = 0.5*(e + f + c);
		double Sbcd = sqrt(s4*(s4 - c)*(s4 - e)*(s4 - f));
		double S = Sabc + Sabd + Sacd + Sbcd;
		point AD1, BD1, CD1;
		AD1.x = AD.end.x - AD.st.x;
		AD1.y = AD.end.y - AD.st.y;
		AD1.z = AD.end.z - AD.st.z;
		BD1.x = BD.end.x - BD.st.x;
		BD1.y = BD.end.y - BD.st.y;
		BD1.z = BD.end.z - BD.st.z;
		CD1.x = CD.end.x - CD.st.x;
		CD1.y = CD.end.y - CD.st.y;
		CD1.z = CD.end.z - CD.st.z;
		double r = fabs(dot(Cross(AD1, BD1), CD1)) / 2.0 / S;
		double ansx, ansy, ansz;
		ansx = (Sabc*a[4].x + Sabd*a[3].x + Sacd*a[2].x + Sbcd*a[1].x) / S;
		ansy = (Sabc*a[4].y + Sabd*a[3].y + Sacd*a[2].y + Sbcd*a[1].y) / S;
		ansz = (Sabc*a[4].z + Sabd*a[3].z + Sacd*a[2].z + Sbcd*a[1].z) / S;
		printf("%.4lf %.4lf %.4lf %.4lf\n", ansx, ansy, ansz, r);
	}
	return 0;
}