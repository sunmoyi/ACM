#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#define maxn 1010

using namespace std;

struct node {
	int w, s;
	int index;
}mouse[maxn];
int dp[maxn];
int pre[maxn];

bool cmp(node a, node b)
{
	if (a.w != b.w)
		return a.w < b.w;
	return a.s > b.s;
}

int main(void)
{
	int i = 1, j;
	while (scanf("%d %d", &mouse[i].w, &mouse[i].s) != EOF)
	{
		dp[i] = 1;
		pre[i] = 0;
		mouse[i].index = i;
		i++;
	}	
	//printf("0\n");
	int n = i - 1;
	sort(mouse + 1, mouse + n + 1, cmp);
	int maxlen = 0;
	int maxi = 0;
	dp[1] = 1;
	//printf(".\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j < i; j++)
		{
			if (mouse[i].w > mouse[j].w && mouse[i].s < mouse[j].s && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				pre[i] = j;
				if (dp[i] > maxlen)
				{
					maxi = i;
					maxlen = dp[i];
				}
			}
		}
	}
	//printf("1\n");
	int t = maxi;
	i = 0;
	stack<int>S;
	while (t != 0)
	{
		S.push(t);
		t = pre[t];
	}
	printf("%d\n", S.size());
	while (!S.empty())
	{
		printf("%d\n", mouse[S.top()].index);
		S.pop();
	}
	return 0;
}