//线性同余方程的标准形式 ax = b(mod m);
// 即 ax mod m == b mod m;
//求 x说有解


#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long  ans[100], x, y, d;

void exgcd(long long a, long long b, long long &d, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1; y = 0;
		d = a;
		return;
	}
	else
	{
		exgcd(b, a % b, d, x, y);
		long long temp = x;
		x = y;
		y = temp - (a / b) * y;
	}
}

int f(int a, int b, int m)
{
	exgcd(a, m, d, x, y);
	if (b % d)
		return -1;
	x = x * (b / d) % m;
	for (int i = 1; i <= d; i++)
		ans[i] = (x + (i - 1) * m / d) % m;
}

int main(void)
{

}