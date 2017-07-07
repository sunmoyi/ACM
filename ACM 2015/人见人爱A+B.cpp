#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a1, a2, b1, b2, c1, c2;
int a3, b3, c3;
int num;

int main(void)
{
	scanf("%d", &num);
	while (num--)
	{
		scanf("%d %d %d %d %d %d", &a1, &b1, &c1, &a2, &b2, &c2);
		c3 = c1 + c2;
		b3 = b1 + b2;
		a3 = a1 + a2;
		if (c3 >= 60)
		{
			c3 -= 60;
			b3++;
		}
		if (b3 >= 60)
		{
			b3 -= 60;
			a3++;
		}
		printf("%d %d %d\n", a3, b3, c3);
	}
	return 0;
}