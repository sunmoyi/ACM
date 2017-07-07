#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

struct k{
	int a;
	int b;
	int c;
}a[105];

int main(void)
{
	int maxx, d;
	queue<k>q;

	while (scanf("%d %d", &maxx, &d) != EOF)
	{
		int xuhao = 0;
		for (int i = 1; i <= maxx; i++)
		{
			scanf("%d", &a[i].a);
			a[i].b = 0;
			a[i].c = ++xuhao;
			q.push(a[i]);
		}
		int ss = 0;
		while (!q.empty())
		{
			k now;
			now = q.front();
			q.pop();
			now.b += d;
			ss = now.c;
			if (now.b >= now.a)
				continue;
			else
				q.push(now);
		}
		printf("%d\n", ss);
	}
	return 0;
}