#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int m;
char str[20];
vector<int>ans;

bool solve(int l, int r, int pre, int tot)
{
	if (tot == m)
	{
		printf("YES\n");
		for (int i = 0; i < tot - 1; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[tot - 1]);
		return true;
	}
	for (int i = 0; i < 10; i++)
	{
		if (!(tot % 2) && (l + i + 1 > r) && ((i + 1) != pre) && (str[i] == '1'))
		{
			ans.push_back(i + 1);
			if (solve(l + i + 1, r, i + 1, tot + 1))
				return true;
			ans.pop_back();
		}
		if ((tot % 2) && (r + i + 1 > l) && ((i + 1) != pre) && (str[i] == '1'))
		{
			ans.push_back(i + 1);
			if (solve(l, r + i + 1, i + 1, tot + 1))
				return true;
			ans.pop_back();
		}
	}
	return false;
}

int main(void)
{
	scanf("%s %d", str, &m);
	if (!(solve(0, 0, 0, 0)))
		printf("NO\n");
	return 0;
}