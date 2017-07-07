#include<cstdio>
#include<cstring>
#include <time.h> 
#include<algorithm>

using namespace std;

int num[11];
int prime[500];
int vis[500];
int phi[500];

void Prime(int n)
{
	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i<n; i++)
	{
		if (!vis[i])
		{
			prime[cnt++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j<cnt&&i*prime[j]<n; j++)
		{
			__int64 k = i*prime[j];
			vis[k] = 1;
			if (i%prime[j] == 0)
			{
				phi[k] = phi[i] * prime[j];
				break;
			}
			else
				phi[k] = phi[i] * (prime[j] - 1);

		}
	}
}

int main(void)
{
	Prime(505);
	srand((unsigned)time(NULL));
	for (int i = 1; i <= 10; i++)
	{
		num[i] = rand() % (500 - 300 + 1) + 300;
		if (!phi[num[i]])
			i--;
	}

	//for (int i = 1; i <= 10; i++)
		//printf("%d ", num[i]);
	//printf("\n");
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j <= 10 - i; j++)
		{
			if (num[j] > num[j + 1])
			{
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
	for (int i = 1; i <= 10; i++)
		printf("%d ", num[i]);
	printf("\n");
	return 0;
}