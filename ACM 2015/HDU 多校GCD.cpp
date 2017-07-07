#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 1000010

using namespace std;

struct node{
	int l, r;
	long long gcd;
}trees[maxn << 2];
long long a[maxn];

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

void pushup(int root)
{
	trees[root].gcd = gcd(trees[root << 1].gcd, trees[root << 1 | 1].gcd);
}

void build(int l, int r, int root)
{
	trees[root].l = l;
	trees[root].r = r;
	if (l == r)
	{
		trees[root].gcd = a[l];
		return;
	}

	int mid = (l + r) >> 1;
	build(l, mid, root << 1);
	build(mid + 1, r, root << 1 | 1);
	pushup(root);
}

long long query(int l, int r, int root)
{
	//printf("%d %d\n", l, r);
	if (l <= trees[root].l && r >= trees[root].r)
		return trees[root].gcd;

	int mid = (trees[root].l + trees[root].r) >> 1;
	long long ans = 0;
	if (r <= mid)
		ans = gcd(ans, query(l, r, root << 1));
	else if (l > mid)
		ans = gcd(ans, query(l, r, root << 1 | 1));
	else
	{
		ans = gcd(ans, query(l, mid, root << 1));
		ans = gcd(ans, query(mid + 1, r, root << 1 | 1));
	}
	return ans;
}

int n;
map<long long, long long>ans;
map<long long, long long>map1;
map<long long, long long>map2;

int main(void)
{
	int T, icase = 1;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		ans.clear();
		map1.clear();
		map2.clear();
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		build(1, n, 1);
		map1[a[1]]++;
		ans[a[1]]++;
		for(int i = 2; i <= n; i++)
		{
			long long now = a[i];
			map2[now]++;
			ans[now]++;
			for(auto it = map1.begin(); it != map1.end(); it++)
			{
				int next = gcd(now, it->first);
				ans[next] += it->second;
				map2[next] += it->second;
			}
			map1.clear();
			for (auto it = map2.begin(); it != map2.end(); it++)
			{
				map1[it->first] = it->second;
			}
			map2.clear();
		}
		int q;
		printf("Case #%d:\n", icase++);
		scanf("%d", &q);
		while(q--)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			//printf("%d %d\n", l, r);
			long long temp = query(l, r, 1);
			printf("%I64d %I64d\n", temp, ans[temp]);
		}
	}
}