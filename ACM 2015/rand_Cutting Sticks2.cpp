
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<time.h>
#define mod 1000

using namespace std;

int num[mod + 1];
bool vis[mod + 1];

FILE *fp = fopen("in.txt", "w");
int main(void)
{
	srand((unsigned)time(NULL));
	for (int i = 1; i <= 100; i++)
	{
		
		int L = rand() % (mod + 1);
		int N = rand() % (L);
		fprintf(fp, "%d\n%d\n", L, N);
		memset(vis, false, sizeof(vis));
		for (int j = 1; j <= N; j++)
		{
			int k = rand() % L;
			while (vis[k])
				k = rand() % L;
			num[j] = k;
			vis[k] = true;
		}
		sort(num + 1, num + N + 1);
		for (int j = 1; j <= N; j++)
			fprintf(fp, "%d ", num[j]);
		fprintf(fp, "\n");
	}
	fprintf(fp, "0\n");
	return 0;
}
*/