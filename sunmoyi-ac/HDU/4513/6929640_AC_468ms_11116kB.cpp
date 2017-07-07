#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010
#define INF 0x3f3f3f3f

using namespace std;

int strin[maxn << 1];
int strout[maxn << 1];
int p[maxn << 1], N;
 
int proc(void)
{
	int len = 1;
	strout[0] = INF;
	int i = 0;
	while (i < N)
	{
		strout[len++] = INF;
		strout[len++] = strin[i];
		i++;
	}
	strout[len++] = INF;
	strout[len] = INF - 3;
	return len;
}

int Manacher(int len)
{
	int i, id = 0, maxx = 0, ans = -1;
	for (i = 1; i <= len; i++)
	{
		if (p[id] + id > i)
			p[i] = min(p[id * 2 - i], p[id] - (i - id));
		else
			p[i] = 1;
		while (strout[i + p[i]] == strout[i - p[i]])
		{
			if (strout[i - p[i]] == INF)
				++p[i];
			else if ((i - p[i] + 2 <= i && strout[i - p[i]] <= strout[i - p[i] + 2]) || i - p[i] + 2 > i)
				++p[i];
			else
				break;
		}
		if (i + p[i] > maxx)
			maxx = i + p[i], id = i;
		ans = max(ans, p[i]);
	}
	return ans - 1;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(strin, -1, sizeof(strin));
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &strin[i]);
		int len = proc();
		int ans = Manacher(len);
		printf("%d\n", ans);
	}
	return 0;
}