#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int N, M;
int minarea = 1 << 30;
int area = 0;
int minv[30];
int mina[30];
int minnrh[30][30][30];

int maxfornrh(int n, int r, int h)
{
	if (minnrh[n][r][h] != 0)
		return minnrh[n][r][h];
	int v = 0;
	for (int i = 0; i < n; i++)
		v += (r - i)*(r - i)*(h - i);
	return minnrh[n][r][h] = v;
}

int dfs(int v, int n, int r, int h)
{
	if (n == 0)
	{
		if (v)
			return 0;
		else
		{
			minarea = min(minarea, area);
			return 0;
		}
	}
	if (v <= 0)
		return 0;
	if (minv[n] > v)
		return 0;
	if (area + mina[n] >= minarea)
		return 0;
	if (h < n || r < n)
		return 0;
	if (maxfornrh(n, r, h) < v)
		return -1;
	for (int rr = r; rr >= n; --rr)
	{
		if (n == M)
			area = rr * rr;
		for (int hh = h; hh >= n; --hh)
		{
			int a;
			area += 2 * rr * hh;
			a = dfs(v - rr * rr * hh, n - 1, rr - 1, hh - 1);
			area -= a * rr * hh;
			if (a == -1)
				break;
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	minv[0] = 0;
	mina[0] = 0;
	for (int i = 1; i <= M; i++)
	{
		minv[i] = minv[i - 1] + i * i * i;
		mina[i] = mina[i - 1] + 2 * i * i;
	}
	if (minv[M] > N)
		printf("0\n");
	else
	{
		int maxH = (N - minv[M - 1]) / (M * N) + 1;
		int maxR = sqrt((N - minv[M - 1]) / M * 1.0) + 1;
		area = 0;
		minarea = 1 << 30;
		dfs(N, M, maxR, maxH);
		if (minarea == 1 << 30)
			printf("0\n");
		else
			printf("%d\n", minarea);
	}
	return 0;
}