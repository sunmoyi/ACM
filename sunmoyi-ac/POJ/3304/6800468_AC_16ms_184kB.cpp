#include <iostream>  
#include <cstdio>  
#include <cmath>  
using namespace std;

const double eps = 1e-8;
const int maxn = 111;

int n;

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
};

struct Line {
	Point a, b;
} line[maxn];

Point operator - (Point a, Point b)
{
	return Point(a.x - b.x, a.y - b.y);
}

double Multi(Point a, Point b)
{
	return a.x * b.y - b.x * a.y;
}

bool Check(Point a, Point b) 
{
	if (fabs(a.x - b.x) < eps && fabs(a.y - b.y) < eps)
		return false;
	for (int i = 0; i < n; i++)
		if (Multi(line[i].a - a, line[i].a - b) * Multi(line[i].b - a, line[i].b - b) > eps) 
			return false;
	return true;
}

int main()
{
	int t, i, j;
	bool flag;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%lf%lf%lf%lf", &line[i].a.x, &line[i].a.y, &line[i].b.x, &line[i].b.y);
		flag = false;
		if (n < 3) flag = true;
		for (i = 0; i < n && !flag; i++) 
		{
			if (Check(line[i].a, line[i].b)) flag = true;
			for (j = i + 1; j < n && !flag; j++)
			{
				if (Check(line[i].a, line[j].a) ||
					Check(line[i].a, line[j].b) ||
					Check(line[i].b, line[j].a) ||
					Check(line[i].b, line[j].b))
					flag = true;
			}
		}
		if (flag) printf("Yes!\n");
		else printf("No!\n");
	}
	return 0;
}