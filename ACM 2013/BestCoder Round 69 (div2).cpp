#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int a, b, c, t;
	int flag = 1;
	while (scanf("%d", &t) != EOF)
	{
	
		while (t--)
		{	
			flag = 1;
			scanf("%d %d %d", &a, &b, &c);
			if (c % 2)
			{
				printf("Impossible\n");
				continue;
			}
			if (a + b > c / 2)
			{
				printf("Impossible\n");
				continue;
			}
			if (a > b)
			{
				flag = 0;
				int temp = a;
				a = b;
				b = temp;
			}
			c /= 2;
			for (int i = c / b; i >= 0; i--)
			{
				int ans = c - b * i;
				int k = ans / a;
				if (ans - k * a == 0)
				{
					if (flag)
					{
						printf("%d %d\n", k* 2, i*2);
						break;
					}
					else
					{
						printf("%d %d\n", i*2, k*2);
						break;
					}
				}
			}
		}
	}
	return 0;
}