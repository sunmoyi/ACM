#include<cstdio>  
#include<iostream>  
#include<cstring>  
#include<cstdlib>  
#include<cmath> 
#include<algorithm>

using namespace std;
struct point
{
	int x, y;
} p[710];

int solve(int n) 
{
	int a, b, c, counts, ans = -1;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			a = p[j].y - p[i].y;  //一般直线方程系数   
			b = p[i].x - p[j].x;
			c = p[i].y*p[j].x - p[i].x*p[j].y;
			counts = 0;
			for (int k = 1; k <= n; k++)
			{
				if (a*p[k].x + b*p[k].y + c == 0) 
					++counts;
			}
			ans = max(counts, ans);
		}
	return ans;
}

int main() 
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
	int ans = solve(n);
	printf("%d\n", ans);
	return 0;
}