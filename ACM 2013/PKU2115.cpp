/***********************************************
 *
 *���� A + CX == B(mod M)
 *�˴�Ϊ cx = b - a(mod 2 ^ k);
 *��չŷ������㷨Ӧ��
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
		b = (long long)1 << k;// d x y ��������  
		ex_gcd(a, b, d, x, y);  // �����c�ǹ�ʽ�е�B - A  a�ǹ�ʽ�е�C  b�ǹ�ʽ�е�M
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