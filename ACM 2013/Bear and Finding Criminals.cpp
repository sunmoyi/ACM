#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int fin[105];
int sum, sit;

int main(void)
{
	int t;
	while (scanf("%d %d", &sum, &sit) != EOF)
	{
		memset(fin, 0, sizeof(fin));
		for (int i = 1; i <= sum; i++)
		{
			scanf("%d", &t);
			fin[abs(sit - i)] += t;
		}
		//for (int i = 0; i <= 10; i++)
			//printf("%d    %d\n", i, fin[i]);
		int k = 0;
		for (int i = 0; i <= 100; i++)
		{
			if (i == 0 && fin[i])
				k++;
			if (sit + i <= sum && sit - i >= 1)
			{
				if (fin[i] == 2)
					k += 2;
			}
			else
			{
				if (fin[i])
					k++;
			}
		}
		printf("%d\n", k);
	}
}