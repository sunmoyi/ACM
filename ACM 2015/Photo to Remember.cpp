#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200010

using namespace std;

int weigh[maxn], heigh[maxn];
int top1, top2;
int num, sum;

int main (void)
{
	while (scanf("%d", &num) != EOF)
	{
		top1 = top2 = sum = 0;
		for (int i = 1; i <= num; i++)
		{
			scanf("%d %d", &weigh[i], &heigh[i]);
			sum += weigh[i];
			if (heigh[i] > top1)
			{
				top2 = top1;
				top1 = heigh[i];
			}
			else if (top2 < heigh[i])
				top2 = heigh[i];
		}

		for (int i = 1; i < num; i++)
		{
			if (heigh[i] == top1)
				printf("%d ", (sum - weigh[i]) * top2);
			else
				printf("%d ", (sum - weigh[i]) * top1);
		}
		if (heigh[num] == top1)
			printf("%d\n", (sum - weigh[num]) * top2);
		else
			printf("%d\n", (sum - weigh[num]) * top1);
	}
	return 0;
}