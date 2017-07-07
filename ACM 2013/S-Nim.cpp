#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int f[101], sg[10001], n, m, t, bead;

int mex(int x)
{
	int a[101] = { 0 };
	for (int i = 0; i < n; i++)
	{
		if (x - f[i] < 0)
			break;
		if (sg[x - f[i]] == -1)
		{
			sg[x - f[i]] = mex(x - f[i]);
		}
		a[sg[x - f[i]]] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (!a[i])
			return i;
	}
}

int main(void)
{
	while (scanf_s("%d", &n) != EOF && n)
	{
		memset(sg, -1, sizeof(sg));
		for (int i = 0; i < n; i++)
			scanf_s("%d", &f[i]);
		sort(f, f + n);

		sg[0] = 0;
		scanf_s("%d", &t);
		while (t--)
		{
			int ans = 0;
			scanf_s("%d", &m);
			while (m--)
			{
				scanf_s("%d", &bead);
				if (sg[bead] == -1)
					sg[bead] = mex(bead);
				ans ^= sg[bead];
			}
			if (ans == 0)
				printf("L");
			else
				printf("W");
		}
		printf("\n");
	}
	return 0;
}