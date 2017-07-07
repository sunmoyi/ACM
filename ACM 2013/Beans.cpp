#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dpx[200000], dpy[200000];
int num[1005][1005];
int n, m;

int main(void)
{\

	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n; i++)
		{
			memset(dpx, 0, sizeof(dpx));
			for (int j = 1; j <= m; j++)
			{
				scanf_s("%d", &num[i][j]);
				if (j > 2)
					dpx[j] = max(dpx[j - 1], dpx[j - 2] + num[i][j]);
				else
				{
					dpx[1] = num[i][1];
					dpx[2] = num[i][2];
				}
			}
			dpy[i] = dpx[m];
		}

		for (int i = 1; i <= n; i++)
		{
			dpy[i] = max(dpy[i - 2] + dpy[i], dpy[i - 1]);
		}

		printf("%d\n", dpy[n]);
	}
	return 0;
}