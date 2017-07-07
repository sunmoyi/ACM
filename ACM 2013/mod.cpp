#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int x;
long long m;
int c, k;
int a, b;
int temp1, temp2, s1, s2, a1, a2;
int len;

int main(void)
{
	int T;
	scanf_s("%d", &T);
	for(int y = 1; y <= T; y++)
	{
		scanf_s("%d %lld %d %d", &x, &m, &k, &c);
		printf("Case #%d:\n", y);
		int ss = k;
		len = 0;
		while (ss > 0)
		{
			len++;
			ss /= 10;
		}
		s1 = m % 6;
		s2 = m - s1 % 6;
		a2 = x +x * 1e1 +  x* 1e2 + x* 1e3 + x* 1e4 + x* 1e5;
		a1 = 0;
		for (int i = 0; i < s1; i++)
		{
			a1 *= 10;
			a1 += x;
		}
		temp1 = a1 % k;// houzhi
		temp2 = a2 % k;// biaozhun



		if(m < 6 && temp1 % k == c)
		{
			printf("YES\n");
			continue;
		}
		else if (m < 6 && temp1 %k != c)
		{
			printf("NO\n");
			continue;
		}
		else
		{
			while (s2 > 1)
			{
				if (s2 % 1)
				{
					a1 = temp2 * pow(10, len) + temp1;
					a2 = temp2 * pow(10, len) + temp2;
					temp1 = a1 % k;
					temp2 = a2 % k;
					s2 /= 2;
				}
				else
				{
					a2 = temp2 * pow(10, len) + temp2;
					temp2 = a2 % k;
					s2 /= 2;
				}
			}
			a1 = temp2 * pow(10, len) + temp1;
			temp1 = a1 % k;

			if (temp1 == c)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}