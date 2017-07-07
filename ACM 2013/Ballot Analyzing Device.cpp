#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char name[1010][1010];
char piao[1010][1010];
int n, m;
int kk[1010];
double rate[1010];
struct node {
	double rate;
	char name[1010];
}people[1010];

bool cmp(node a, node b)
{
	return a.rate > b.rate;
}

int main(void)
{
	freopen("bad.in", "r", stdin);
	freopen("bad.out", "w", stdout);

	scanf_s("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%s", people[i].name, 1000);
	}
	memset(kk, 0, sizeof(kk));
	int summ = 0;
	for (int i = 1; i <= m; i++)
	{
		scanf_s("%s", piao[i], 1000);
		int sum = 0;
		int k = 0;
		for (int j = 0; j < n; j++)
		{
			if (piao[i][j] == 'X')
			{
				sum++;
				k = j;
			}
		}
		if (sum == 1)
		{
			kk[k + 1]++;
			summ++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		people[i].rate = (kk[i] * 1.0 / m * 100.0);
	}
	sort(people + 1, people + n + 1, cmp);

	for (int i = 1; i <= n; i++)
	{
		printf("%s %.2lf%%\n", people[i].name, people[i].rate);
	}
	printf("Invalid %.2lf%%\n", ((m - summ)*1.0) / m * 100);
	return 0;
}