/***********************************
 *
 *PKU 1061
 *
 *对应方程组
 *(n - m) t + Lp = x - y;
 *
 *n m : 青蛙的每次跳跃长度
 *L 赤道的周长
 *x y: 开始时的坐标
 *p 术语全体整数集的一个数  代表需要绕赤道的圈数
 *
 *具解题过程
 *1. 写出方程组， 此方程对应的函数调用是 exgcd(n - m , L, x, y); 注意这里得到的是一个解 但不是唯一或者说是确定解
 *2.若（x - y） % gcd(n - m, l) == 0  无解
 *3.若(x - y) gcd(n - m, L) == 0
 *4.有解后设M = gcd(n - m, l), x = x(x - y) / M;
 *5.然后(x % (L / M) + (L / M)) % (L / M);
 ***********************************/


#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y)//欧几里得算法的扩展
{
	long long r, t;
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	r = exgcd(b, a%b, x, y);
	t = x;
	x = y;
	y = t - a / b*y;
	return r;
}

int main()
{
	long long x, y, m, n, l, xx, yy, d, r;
	scanf_s("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l);
	d = exgcd(n - m, l, xx, yy);

	if ((x - y) % d != 0)
	{
		printf("Impossible\n");
	}
	else
	{
		xx = xx * ((x - y) / d);
		r = l / d;
		xx = (xx % r + r) % r;//求出最小非负整数解
		printf("%lld\n", xx);
	}
	return 0;
}
