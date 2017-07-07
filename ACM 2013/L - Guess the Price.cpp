#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>

using namespace std;

int ans;
int a, b, c, b1, c1;

int main(void)
{
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf("%d %d %d", &a, &b, &c);
			b1 = abs(a - b);
			c1 = abs(a - c);
			if (b1 < c1)
				printf("A\n");
			else
				printf("B\n");
		}
	}
	return 0;
}