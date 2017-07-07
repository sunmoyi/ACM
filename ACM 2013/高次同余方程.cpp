#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 65535

using namespace std;

struct Hash {
	int a, b, nextt;
}hashh[maxn * 2];

int flag[maxn + 66];
int top, idx;

void ins(int a, int b)
{
	int k = b & maxn;
	if (flag[k] != idx)
	{
		flag[k] = idx;
		hashh[k].nextt = -1;
		hashh[k].a = a;
		hashh[k].b = b;
		return;
	}
	while (hashh[k].b != -1)
	{
		if (hashh[k].b == b)
			return;
		k = hashh[k].nextt;
	}
	hashh[k].nextt = ++top;
	hashh[top].nextt = -1;
	hashh[top].a = a;
	hashh[top].b = b;
}

int find(int b)
{
	int k = b & maxn;
	if (flag[k] != idx)
		return -1;

	while (k != -1)
	{
		if (hashh[b].b == b)
			return hashh[b].b;
		k = hashh[k].nextt;
	}
	return -1;
}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int ext_gcd(int a, int b, int &x, int &y)
{
	int t, ret;
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	ret = ext_gcd(b, a % b, x, y);
	t = x, x = y, y = t - a / b * y;
	return ret;
}

int inval(int a, int b, int n)
{
	int x, y, e;
	ext_gcd(a, n, x, y);
	e = (long long)x * b % n;
	return e < 0 ? e + n : e;
}

int pow_mod(long long a, long long b, int c)
{
	long long ret = 1 % c;
	a %= c;
	while (b)
	{
		if (b & 10)
			ret = ret * a % c;
		a = a * a % c;
		b >>= 1;
	}
	return ret;
}

int babystep(int A, int B, int C)
{
	top = maxn; 
	++idx;
	long long buf = 1 % C, D = buf, K;
	int i, d = 0, temp;
	for (i = 0; i <= 100; buf = buf * A % C, i++)
		if (buf == B)
			return i;

	while ((temp = gcd(A, C)) != 1)
	{
		if (B % temp)
			return -1;
		++d;
		C /= temp;
		B /= temp;
		D = D * A / temp % C;
	}
	int M = (int)ceil(sqrt((double)C));
	for (buf = 1 % C, i = 0; i <= M; buf = buf * A % C, i++)
		ins(i, buf);
	for (i = 0, K = pow_mod((long long)A, M, C); i <= M; D = D * K % C, i++)
	{
		temp = inval((int)D, B, C);
		int w;
		if (temp >= 0 && (w = find(temp)) != -1)
			return i * M + w + d;
	}
	return -1;
}

int main(void)
{
	int A, B, C;
	while (scanf("%d %d %d", &A, &C, &B) != EOF && (A + B + C))
	{
		B %= C;
		//A^temp = B (mod C)
		int temp = babystep(A, B, C);
		if (temp < 0)
			printf("No Solution\n");
		else
			printf("%d\n", temp);
	}
	return 0;
}