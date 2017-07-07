#include <algorithm>            
#include <cstdio>    
#include <string>       
#include <cmath>          
#define p (1.0/2)    

const int maxn = 10100;

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, x;
		scanf("%d %d", &n, &x);
		double c1 = (1.0 / 2);
		double c2 = 1.0;
		double p1 = p;
		double p2 = 1.0;
		if (x == 0 || n == 0 || x == n)
		{
			printf("0.0000\n");
			continue;
		}
		for (int i = x - 2; i > 0; i--)
		{
			double t = c1;
			double tt = c2;
			c1 = p / (1 - t*p);
			c2 = (1.0 + tt*p) / (1 - t*p);
		}
		for (int i = x + 2; i < n; i++)
		{
			double t = p1;
			double tt = p2;
			p1 = p / (1 - (t*1.0) / 2);
			p2 = (1.0 + tt*p) / (1 - t*p);
		}
		   
		double s = ((c2 + p2)*p + 1) / (1 - (p1 + c1)*p);
		if (n - x == 1 || x == 1)
			s /= 2;
		printf("%.4lf\n", s);
	}
}