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

//a ^ b �ǵݹ�
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

//�ȱ����ж������ȡģ
//sn = a + a^2 + a^3 + ���� + a^n;
//Ҫ�� sn mod P
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
//����a * b;
Matrix Product(Matrix a, Matrix b, int p)
{

}
//���� a ^ b mod p;
Matrix Pow(const Matrix & m, int k, int p)
{ //��mk mod p
	int r = m.r;
	Matrix result(r);
	result.makeI(); //MakeI�ǽ�result��Ϊ��λ����
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
//�� ax+by=gcd(a,b)��������,����gcd(a,b)
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

//��ŷ������
int euler(int n)
{
	int ret = 1;
	for (int i = 2; i*i <= n; i++) { //ֻҪ����sqrt(n)���ڵ�����
		if (n%i == 0) {//i���Ǻ����򲻿������������
			n /= i, ret *= i - 1; //����ܻ�ʣһ��i,n/i������i
			while (n%i == 0) {
				n /= i, ret *= i;
			}
		}
	}
	if (n>1) ret *= n - 1;
	return ret;
}

//O(N)�������
int main()
{
	int n;
	cin >> n; //��n��������
	vector<int> prime; vector<bool> isPrime(n + 1);
	for (int i = 1; i <= n; ++i)
		isPrime[i] = true;
	for (int i = 2; i <= n; ++i)
	{
		if (isPrime[i]) //����iʱ����û��ɾ������iΪ����
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