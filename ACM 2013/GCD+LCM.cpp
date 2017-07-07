#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<ctime>
#define Times 11
#define N 501
#define C 201
/**************************************************
已知[a, b] 和(a, b)， 求a, b 如果有多组， 输出a + b 最小的

(a * b) / gcd = lcm;
(a / gcd * b / gcd) * gcd = lcm
a/gcd * b / gcd = lcm / gcd
令key = lcm / gcd
分解质因数x, y → x * y = key
x * gcd = a;
y * gcd = b;
1.求key
2.find驱动pollard_rho函数分解质因数
	在pollard_rho运行的过程中需要用miller_rabin来判断是否是质数
	用Witness来对miller_rabin进行二次探测
	quick_mod multi 进行快速取模运算
3.dfs对分解之后的质因数进行深搜
	在这里我们要 x = a / gcd  y = b / gcd 
	所以 x y 一定是互素的。
***************************************************/
using namespace std;

unsigned long long key, a, b, gd, lm, res_a, res_b, mini;
int ct;
long long jl[N];

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

long long random(long long n)
{
	return (long long)((double)rand() / RAND_MAX * n + 0.5);
}

long long multi(long long a, long long b, long long m)
{
	long long ret = 0;
	while (b > 0)
	{
		if (b & 1)
			ret = (ret + a) % m;
		b >>= 1;
		a = (a << 1) % m;
	}
	return ret;
}

long long quick_mod(long long a, long long b, long long m)
{
	long long ans = 1;
	a %= m;
	while (b)
	{
		if (b & 1)
		{
			ans = multi(ans, a, m);
			b--;
		}
		b /= 2;
		a = multi(a, a, m);
	}
	return ans;
}

bool Witness(long long a, long long n)
{
	long long m = n - 1;
	int j = 0;
	while (!(m & 1))
	{
		j++;
		m >>= 1;
	}
	long long x = quick_mod(a, m, n);
	if (x == 1 || x == n - 1)
		return false;
	while (j--)
	{
		x = x * x % n;
		if (x == n - 1)
			return false;
	}
	return true;
}

bool miller_rabin(long long n)
{
	if (n < 2)
		return false;
	if (n == 2)
		return true;
	if (!(n & 1))
		return false;
	for (int i = 1; i <= Times; i++)
	{
		long long a = random(n - 2) + 1;
		if (Witness(a, n))
			return false;
	}
	return true;
}

long long pollard_rho(long long n, int c)
{
	long long x, y, d, i = 1, k = 2;
	x = random(n - 1) + 1;
	y = x;
	while (1)
	{
		i++;
		x = (multi(x, x, n) + c) % n;
		d = gcd(y - x, n);
		if (1 < d && d < n)
			return d;
		if (y == x)
			return n;
		if (i == k)
		{
			y = x;
			k <<= 1;
		}
	}
}

void find(long long n, int k)
{
	if (n == 1)
		return;
	if (miller_rabin(n))
	{
		jl[++ct] = n;
		return;
	}
	long long p = n;
	while (p >= n)
		p = pollard_rho(p, k--);
	find(p, k);
	find(n/p, k);

}

unsigned long long NumFactor[650];
int Num[65], Len;

void DFS(int cur, unsigned long long value)
{
	unsigned long long s = 1;
	if (cur == Len + 1)
	{
		a = value;
		b = key / value;
		if (gcd(a, b) == 1)
		{
			a *= gd;
			b *= gd;
			if (a + b < mini)
			{
				mini = a + b;
				res_a = a < b ? a : b;
				res_b = a > b ? a : b;
			}
		}
		return;
	}
	for (int i = 0; i <= Num[cur]; i++)
	{
		if (value * s >= mini)
			return;
		DFS(cur + 1, value * s);
		s *= NumFactor[cur];
	}
}

void solve(long long n)
{
	ct = 0;
	find(n, C);
	sort(jl + 1, jl + ct);
	Len = 0;
	memset(Num, 0, sizeof(Num));
	Num[0] = 1;
	NumFactor[0] = jl[1];
	for (int i = 2; i <= ct; i++)
	{
		if (NumFactor[Len] != jl[i])
			NumFactor[++Len] = jl[i];
		Num[Len]++;
	}
	DFS(0, 1);
}

int main()
{
	while (scanf("%llu %llu", &gd, &lm) != EOF)
	{
		if (gd == lm)
		{
			printf("%llu %llu\n", gd, lm);
			continue;
		}
		mini = -1;
		key = lm / gd;
		solve(key);
		printf("%llu %llu\n", res_a, res_b);
	}
	return 0;
}