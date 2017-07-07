#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[1005];

int main(void)
{
	int ans;
	while (scanf("%d", &ans) != EOF && ans)
	{
		for (int i = 1; i <= ans; i++)
		{
			scanf("%d", &num[i]);
		}
		int k = num[1];
		for (int i = 2; i <= ans; i++)
		{
			k ^= num[i];
		}
		if (k == 0)
			printf("Grass Win!\n");
		else
			printf("Rabbit Win!\n");
	}
	return 0;
}