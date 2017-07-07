#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct node{
	long long k;
	long long t;
	long long v;
	node(long long k = 0, long long t = 0, long long v = 0) : k(k), t(t), v(v){}
};

long long n, m, t, a[50005], sum, flag;
vector<node>vet[10005];
long long vist[10005], dis[10005];

long long spfa(long long num)
{
	long long minn = a[num];
	for (long long i = 0; i <= n; i++)
	{
		dis[i] = ((long long) 1 << 25);
		vist[i] = 0;
	}
	dis[1] = 0;
	vist[1] = 1;
	queue<long long>Q;
	Q.push(1);
	while (!Q.empty())
	{
		long long x = Q.front();
		Q.pop();
		vist[x] = 0;
		for (long long i = 0; i < vet[x].size(); i++)
		{
			node p = vet[x][i];
			if (p.v >= minn)// 
			{
				if (dis[p.k] > dis[x] + p.t)
				{
					dis[p.k] = dis[x] + p.t;
					if (!vist[p.k])
						Q.push(p.k); 
					vist[p.k] = 1;
				}
			}
		}
	}
	if (dis[n] <= t)
		return 1;
	else
		return 0;
}

int main(void)
{
	int text;
	while (scanf_s("%d", &text) != EOF)
	{
		while (text--)
		{
			long long cnt = 0;
			scanf_s("%lld %lld %lld", &n, &m, &t);
			for (long long i = 0; i <= n; i++)
				vet[i].clear();
			for (long long i = 0; i < m; i++)
			{
				long long v1, v2, tmp, tmp1;
				scanf_s("%lld %lld %lld %lld", &v1, &v2, &tmp, &tmp1);
				vet[v1].push_back(node(v2, tmp1, tmp));
				vet[v2].push_back(node(v1, tmp1, tmp));
				a[cnt++] = tmp;
			}
			sort(a, a + cnt);

			long long ll = 0, rr = cnt - 1;
			long long ans = 0;
			while (ll <= rr)
			{
				long long mid = (ll + rr) / 2;
				if (spfa(mid))
				{
					if (ans < a[mid])
						ans = a[mid];
					ll = mid + 1;
				}
				else
					rr = mid - 1;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}