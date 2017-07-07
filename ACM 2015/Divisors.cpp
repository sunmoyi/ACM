#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool isprime[10000];
int prime[10000];
int jie[440][86];
long long zu[500][500];
int p[85];
int k = 0;

void prim()
{
	memset(isprime, false, sizeof(isprime));
	isprime[1] = isprime[0] = true;
	for (int i = 2; i <= 440; i++)
	{
		if (!isprime[i])
		{
			prime[k++] = i;
			for (int j = 2; i * j <= 440; j++)
			{
				isprime[i * j] = true;
			}
		}
	}
}

void fen()
{
	memset(jie, 0, sizeof(jie));
	for (int i = 0; i < k; i++)
	{
		for (int j = 2; j < 440; j++)
		{
			jie[j][i] = j / prime[i] + jie[j / prime[i]][i];
		}
	}
}

void zuhe()
{
	for (int i = 2; i < 432; i++)
	{
		for (int j = 1; j < i; j++)
		{
			zu[i][j] = 1;
			for (int i1 = 0; i1 < k && jie[i][i1]; i1++)
			{
				int side = jie[i][i1] - jie[j][i1] - jie[i - j][i1];
				if (side)
					zu[i][j] *= (side + 1);
			}
		}
	}
}	

int main(void)
{
	prim();
	//printf("1\n");
	fen();
	//printf("1\n");
	zuhe();
	//printf("1\n");
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (m == 0 || m == n)
			printf("1\n");
		else
			printf("%lld\n", zu[n][m]);
	}
	return 0;
}