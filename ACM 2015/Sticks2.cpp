#include<cstdio>
#include<cstdio>
#include<algorithm>

using namespace std;

struct node {
	int len;
	bool mark = false;
}a[10];
int sum, lenn, num, tim;

bool cmp(node a, node b)
{
	return a.len > b.len;
}

bool dfs(int s, int pis, int pos)
{
	if (s == tim)
		return true;
	for (int i = pos = 1; i <= num; i++)
	{
		if (a[i].mark)
			continue;
		if (pis + a[i].len == lenn)
		{
			a[i].mark = true;
			if (dfs(s + 1, 0, 0))
				return true;
			a[i].mark = false;
		}
		else if (pis + a[i].len < lenn)
		{
			a[i].mark = true;
			if (dfs(s, pis + a[i].len, i))
				return true;
			a[i].mark = false;
			if (pis == 0)
				return false;
			while (a[i].len == a[i + 1].len)
				i++;
		}
	}
	return false;
}

int main(void)
{
	while (scanf("%d", &num) != EOF && num)
	{
		sum = 0;
		int maxx = -1;
		for (int i = 1; i <= num; i++)
		{
			scanf("%d", &a[i].len);
			a[i].mark = false;
			sum += a[i].len;
			maxx = max(maxx, a[i].len);
		}

		sort(a + 1, a + num + 1, cmp);

		for (lenn = maxx; lenn <= sum; lenn++)
		{
			if (sum % lenn)
				continue;
			tim = sum / lenn;
			if (dfs(0, 0, 0))
			{
				printf("%d\n", lenn);
				break;
			}
		}
	}
	return 0;
}