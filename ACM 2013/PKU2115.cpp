/***********************************************
 *
 *方程 A + CX == B(mod M)
 *此处为 cx = b - a(mod 2 ^ k);
 *拓展欧几里得算法应用
 *
 ***********************************************/

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

void ex_gcd(long long a, long long b, long long &d, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		d = a;
		return;
	}
	else
	{
		ex_gcd(b, a % b, d, x, y);
		long long temp = x;
		x = y;
		y = temp - (a / b) * y;
	}
}

int main(void)
{
	long long x, y, m, n, l;
	long long a, b, c, d, k;
	while (scanf("%lld %lld %lld %lld", &a, &b, &c, &k) != EOF && a + b + c + k)
	{
		long long temp = c;
		c = b - a;
		a = temp;
		b = (long long)1 << k;// d x y 都是引用  
		ex_gcd(a, b, d, x, y);  // 这里的c是公式中的B - A  a是公式中的C  b是公式中的M
		if (c %d != 0)
			printf("FOREVER\n");
		else
		{
			long long ans = x * c / d;
			long long temp = b / d;
			ans = ans % temp + temp;
			printf("%lld\n", ans % temp);
		}
	}
	return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
}