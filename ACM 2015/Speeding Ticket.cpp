#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int speed[110];
int lit[110];

int n, m;
int t, speedd, l, r;

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		l = r = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &t, &speedd);
			//if (speedd > 100)
			//	speedd = 100;
			for (int j = l + 1; j <= l + t; j++)
				speed[j] = speedd;
			l += t;
		}

		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d", &t, &speedd);
			for (int j = r + 1; j <= r + t; j++)
				lit[j] = speedd;
			r += t;
		}

		int maxx = -9999;
		for (int i = 1; i <= 100; i++)
			//if(speed[i] - lit[i] > 0)
				maxx = max(maxx, lit[i] - speed[i]);

		if (maxx <= 0)
			printf("0\n");
		else
			printf("%d\n", maxx);
	}
	return 0;
}