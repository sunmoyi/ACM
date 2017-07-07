#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;

int ans, sum, num[100010];
int start, maxx, temp; 
int fin1, fin2;

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		for (int s = 1; s <= ans; s++)
		{
			scanf_s("%d", &sum);
			for (int i = 1; i <= sum; i++)
				scanf_s("%d", &num[i]);

			maxx = INT_MIN;
			fin1 = fin2 = start  = 1;
			temp = 0;
			for (int i = 1; i <= sum; i++)
			{
				temp += num[i];
				if (temp > maxx)
				{
					maxx = temp;
					fin1 = start, fin2 = i;
				}
				if (temp < 0)
				{
					temp = 0;
					start = i + 1;
				}
			}
			printf("Case %d:\n", s);
			printf("%d %d %d\n", maxx, fin1, fin2);
			if (s != ans)
				printf("\n");
		}
	}
	return 0;
}