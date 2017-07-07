#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
#define maxn 200010
#define INF 0x3f3f3f3f

using namespace std;

int a[maxn], r[maxn], l[maxn], res[maxn];

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		stack<int>S;
		for (int i = 1; i <= n; i++)
		{
			res[i] = 0;
			while (!S.empty() && a[S.top()] >= a[i])
				S.pop();
			if (S.empty())
				l[i] = 0;
			else
				l[i] = S.top();
			S.push(i);
		}
		while (!S.empty())
			S.pop();
		for (int i = n; i >= 1; i--)
		{
			while (!S.empty() && a[S.top()] >= a[i])
				S.pop();
			if (S.empty())
				r[i] = n + 1;
			else
				r[i] = S.top();
			S.push(i);
		}

		for (int i = 1; i  <= n; i++)
		{
			int x = r[i] - l[i] - 1;
			res[x] = max(res[x], a[i]);
		}
		for (int i = n - 1; i > 0; i--)
			res[i] = max(res[i + 1], res[i]);
		for (int i = 1; i <= n; i++)
			printf("%d%c", res[i], " \n"[i == n]);
	}
	return 0;
}