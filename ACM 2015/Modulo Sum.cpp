#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1100

using namespace std;

int n, m, a;
bool flag = false, vis[maxn];
vector<int>sum;

int main(void)
{
	scanf("%d %d", &n, &m);
	vector<int>sum;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		a %= m;
		int len = sum.size();
		for (int j = 0; j < len; j++)
		{
			int newsum = (sum[j] + a) % m;
			if (newsum == 0)
			{
				flag = true;
				break;
			}
			if (!vis[newsum])
			{
				sum.push_back(newsum);
				vis[newsum] = 1;
			}
		}
		if (!vis[a])
		{
			if (a == 0)
			{
				flag = true;
				break;
			}
			sum.push_back(a);
			vis[a] = true;
		}
		if (flag)
			break;
	}
	if (flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}