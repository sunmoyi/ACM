/***********************************
 *
 *PKU 1061
 *
 *��Ӧ������
 *(n - m) t + Lp = x - y;
 *
 *n m : ���ܵ�ÿ����Ծ����
 *L ������ܳ�
 *x y: ��ʼʱ������
 *p ����ȫ����������һ����  ������Ҫ�Ƴ����Ȧ��
 *
 *�߽������
 *1. д�������飬 �˷��̶�Ӧ�ĺ��������� exgcd(n - m , L, x, y); ע������õ�����һ���� ������Ψһ����˵��ȷ����
 *2.����x - y�� % gcd(n - m, l) == 0  �޽�
 *3.��(x - y) gcd(n - m, L) == 0
 *4.�н����M = gcd(n - m, l), x = x(x - y) / M;
 *5.Ȼ��(x % (L / M) + (L / M)) % (L / M);
 ***********************************/


#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y)//ŷ������㷨����չ
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
		xx = (xx % r + r) % r;//�����С�Ǹ�������
		printf("%lld\n", xx);
	}
	return 0;
}
