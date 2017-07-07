#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
#define MAX 1007

using namespace std;

struct Node
{
	int c, p, id;
	bool operator < (const Node & a) const
	{
		if (p == a.p) return c < a.c;
		return p > a.p;
	}
}p[MAX];
struct PP
{
	int a, b;
	PP(int x, int y)
	{
		a = x;
		b = y;
	}
	bool operator < (const PP &x) const
	{
		return a < x.a;
	}
};
int n, k, r, m;
multiset<PP> table;
vector<pair<int, int> > pp;

int main(void)
{
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &p[i].c, &p[i].p);
			p[i].id = i + 1;
		}
		sort(p, p + n);
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &r);
			table.insert(PP(r, i + 1));
		}
		int ans = 0;
		multiset<PP>::iterator it;
		for (int i = 0; i < n; i++)
		{
			it = table.lower_bound(PP(p[i].c, 1));
			if (it == table.end()) 
				continue;
			ans += p[i].p;
			table.erase(it);
			pp.push_back(make_pair(p[i].id, it->b));
		}
		printf("%d %d\n", (int)pp.size(), ans);
		for (int i = 0; i < pp.size(); i++)
			printf("%d %d\n", pp[i].first, pp[i].second);
	}
}