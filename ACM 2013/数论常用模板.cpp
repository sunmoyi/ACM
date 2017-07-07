#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iostream>

using namespace std;

//a ^ b
long long pow(long long a, long long b)
{
	if (b == 0)
		return 1;
	if (b & 1)
		return a * pow(a, b - 1);
	else
	{
		int t = pow(a, b / 2);
		return t * t;
	}
}

//a ^ b 非递归
long long pow(long long a, long long b)
{
	long long res = 1;
	long long base = a;
	while (b)
	{
		if (b & 1)
			res *= base;
		base *= base;
		b >>= 1;
	}
	return res;
}

//(a ^ b) % c
long long  powmod(long long a, long long b, long long c)
{
	int res = 1;
	int base = a % c;
	while (b)
	{
		if (b & 1)
			res = (res * base) % c;
		base = (base * base) % c;
		b >>= 1;
	}
	return res;
}

//等比数列二分求和取模
//sn = a + a^2 + a^3 + …… + a^n;
//要求 sn mod P
long long powsummod(long long a, long long n, long long p)
{
	if (n == 1)
		return a % p;
	if (n % 2 == 0)
		return (1 + powmod(a, n / 2, p)) * powsummod(a, (n - 1) / 2, p) % p;
	else
		return ((1 + powmod(a, (n - 1) / 2, p)) * powsummod(a, (n - 1) / 2, p) + powmod(a, n, p)) % p;
}

struct Matrix{
	long long a[32][32];
	int r;
	Matrix(int rr) :r(rr) {}
	void makeI()
	{
		memset(a, 0, sizeof(a));
		for (int i = 0; i < r; i++)
			a[i][i] = 1;
	}
};
//矩阵a * b;
Matrix Product(Matrix a, Matrix b, int p)
{

}
//矩阵 a ^ b mod p;
Matrix Pow(const Matrix & m, int k, int p)
{ //求mk mod p
	int r = m.r;
	Matrix result(r);
	result.makeI(); //MakeI是将result变为单位矩阵
	Matrix base = m;
	while (k) {
		if (k & 1)
			result = Product(result, base, p); //result*base mod p
		k >>= 1;
		base = Product(base, base, p);
	}
	return result;
}

int GcdEx(int a, int b, int &x, int & y)
//求 ax+by=gcd(a,b)的整数解,返回gcd(a,b)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int gcd = GcdEx(b, a%b, x1, y1);
	x = y1;
	y = x1 - a / b * y1;
	return gcd;
}

//求欧拉函数
int euler(int n)
{
	int ret = 1;
	for (int i = 2; i*i <= n; i++) { //只要考虑sqrt(n)以内的素数
		if (n%i == 0) {//i若是合数则不可能满足此条件
			n /= i, ret *= i - 1; //最后总会剩一个i,n/i不整除i
			while (n%i == 0) {
				n /= i, ret *= i;
			}
		}
	}
	if (n>1) ret *= n - 1;
	return ret;
}

//O(N)素数打表
int main()
{
	int n;
	cin >> n; //求n以内素数
	vector<int> prime; vector<bool> isPrime(n + 1);
	for (int i = 1; i <= n; ++i)
		isPrime[i] = true;
	for (int i = 2; i <= n; ++i)
	{
		if (isPrime[i]) //处理到i时它还没被删掉，则i为素数
			prime.push_back(i);
		for (int j = 0; j < prime.size(); ++j) 
		{
			if (i*prime[j] <= n)
				isPrime[i*prime[j]] = false;
			else break;
			if (i % prime[j] == 0)
				break;
		}
	}
	for (int i = 0; i < prime.size(); ++i)
		cout << prime[i] << endl;
	return 0;
}