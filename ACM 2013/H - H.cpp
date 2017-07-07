#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans;
int sum, num, time;
int timee[100005];

bool cmp(int a, int b)
{
	return a > b;
}

int main(void)
{
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf("%d %d %d", &sum, &num, &time);
			for (int i = 1; i <= sum; i++)
			{
				scanf("%d", &timee[i]);
			}

			sort(timee + 1, timee + 1 + sum, cmp);

			int j = 1;
			int maxx;

			if (num > 1)
				maxx = timee[1];
			else
				maxx = 0;
			
			for (int i = num; i <= sum; i++, j++)
			{
				timee[i] += time * j;
				if (timee[i] > maxx)
					maxx = timee[i];
			}
			printf("%d\n", maxx);
		}
	}
	return 0;
}