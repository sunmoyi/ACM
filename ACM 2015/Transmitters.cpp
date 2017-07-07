#include <iostream>  
#include <string.h>  
#include <algorithm>  
#include <stdio.h>  
#include <math.h>  

using namespace std;

const int N = 50000;
const double eps = 1e-9;

struct Point
{
	double x, y;
};

Point p[N];

double cross(Point A, Point B, Point C)
{
	return (B.x - A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x);
}

double dist(Point A, Point B)
{
	return (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y);
}

int main()
{
	int k, n;
	Point t, cir;
	double d, r;
	while (cin >> cir.x >> cir.y >> r)
	{
		k = 0;
		if (r<0) break;
		cin >> n;
		for (int i = 0; i<n; i++)
		{
			cin >> t.x >> t.y;
			d = dist(t, cir);
			if (d<r*r || fabs(d - r*r)<eps) //表示点在圆内或者在圆上  
			{
				p[k].x = t.x;
				p[k].y = t.y;
				k++;
			}
		}
		int maxval = 0;
		for (int i = 0; i<k; i++)
		{
			int count = 1;
			for (int j = 0; j<k; j++)
			{
				if (i != j&&cross(cir, p[i], p[j]) >= 0)
					count++;
			}
			if (count>maxval) maxval = count;
		}
		cout << maxval << endl;
	}
	return 0;
}