#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

#define lowbit(x) (x&(-x))

int t, n, bit[N], x[N], v[N];

void add(int x, int v) 
{
	while (x <= n)
	{
		bit[x] += v;
		x += lowbit(x);
	}
}

int find(int x) 
{
	int ans = 0, num = 0;
	for (int i = 16; i >= 0; i--) 
	{
		ans += (1 << i);
		if (ans >= n || num + bit[ans] >= x)
			ans -= (1 << i);
		else num += bit[ans];
	}
	return ans + 1;
}

void add2(int x, int v) 
{
	while (x <= n)
	{
		bit[x] = max(bit[x], v);
		x += lowbit(x);
	}
}

int get(int x) 
{
	int ans = 0;
	while (x) 
	{
		ans = max(ans, bit[x]);
		x -= lowbit(x);
	}
	return ans;
}

int main() 
{
	int cas = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		memset(bit, 0, sizeof(bit));
		for (int i = 1; i <= n; i++) 
		{
			scanf("%d", &x[i]);//x[i]存放数字i所放置的位置
			add(i, 1);
		}//bit数组存储空位的个数
		for (int i = n; i >= 1; i--) 
		{
			x[i] = find(x[i] + 1);
			add(x[i], -1);
		}
		memset(bit, 0, sizeof(bit));
		printf("Case #%d:\n", ++cas);
		for (int i = 1; i <= n; i++) 
		{
			int Max = get(x[i] - 1) + 1;
			add2(x[i], Max);
			printf("%d\n", get(n));
		}
		printf("\n");
	}
	return 0;
}