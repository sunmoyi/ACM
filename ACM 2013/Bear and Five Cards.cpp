#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int fin[105];

int main(void)
{
	int t;
	while (scanf("%d", &t) != EOF)
	{
		int sum = 0;
		memset(fin, 0, sizeof(fin));
		fin[t]++;
		sum += t;
		for (int i = 1; i <= 4; i++)
		{
			scanf("%d", &t);
			fin[t]++;
			sum += t;
		}
		int maxx = 0;
		for (int i = 100; i >= 1; i--)
		{
			if (fin[i] == 2)
				maxx = max(maxx, i * 2);
			else if (fin[i] >= 3)
				maxx = max(maxx, i * 3);
		}
		printf("%d\n", sum - maxx);
	}
	return 0;
}