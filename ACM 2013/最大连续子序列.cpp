#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int sum, num[10010];
int maxx, start, fin1, fin2;

int main(void)
{
	while (scanf_s("%d", &sum) != EOF && sum)
	{
		for (int i = 1; i <= sum; i++)
			scanf_s("%d", &num[i]);

		maxx = INT_MIN;
		start = fin1 = 1;
		fin2 = -1;
		int temp = 0;
		for (int i = 1; i <= sum; i++)
		{
			temp += num[i];
			if (temp > maxx && temp >= 0)
			{
				maxx = temp;
				fin1 = start;
				fin2 = i;
			}
			if (temp < 0)
			{
				temp = 0;
				start = i + 1;
			}
		}
		if (fin2 == -1)
			fin2 = sum;
		if (maxx < 0)
			maxx = 0;
		printf("%d %d %d\n", maxx, num[fin1], num[fin2]);
	}
	return 0;
}