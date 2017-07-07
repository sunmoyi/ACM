#include<stdio.h>
#include<stdlib.h>
#include<cmath>

using namespace std;

const double eps = 1e-10;
const int offset = 1000;

struct point
{
	double x, y;
}p[105], p1, p2;

bool iszero(double x)
{
	return fabs(x) < eps;       
}

double Crossleft(point A, point B, point C) 
{
	return (B.x - A.x) * (C.y - A.y) - (B.y - A.y)*(C.x - A.x);
}
//点p1再点集p内
int InPolygon(int n)
{
	int cnt, i = 0;
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

int main()
{
	int T, n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);

		scanf("%d", &T);
		while (T--)
		{
			scanf("%lf%lf", &p1.x, &p1.y);
			if (InPolygon(n))  
				printf("Yes\n");
			else               
				printf("No\n");
		}
	}
}


