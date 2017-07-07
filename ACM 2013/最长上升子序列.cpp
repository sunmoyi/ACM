#include<stdio.h>
#include<string.h>
#define N 20005
#include<algorithm>
using namespace std;
int stack[N];
int dp[N];
int maxx;
int n;
struct node
{
	int w;
	int h;
}a[N];
int cmp(struct node b, struct node c)
{
	if (b.w == c.w)
		return b.h<c.h;
	else return b.w>c.w;
}
void LIS()
{
	//dp[i]表示前i个数字中加上第i个数字后，有几个数字是递增的，即前i个数字中有多少个比第i个数字小的+1
	//int stack[N];
	memset(dp, 0, sizeof(dp));
	memset(stack, 0, sizeof(stack));
	int top = 0;
	stack[top] = -99999999;
	maxx = -1;
	for (int i = 1; i <= n; i++)
	{
		//如果a[i]>栈顶部元素，则压栈
		if (a[i].h >= stack[top])
		{
			stack[++top] = a[i].h;
			dp[i] = top;
		}
		//如果a[i]不大于栈顶部元素，则二分查找第一个比a[i]大的元素
		else
		{
			int l = 1, r = top;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (a[i].h >= stack[mid])
				{
					l = mid + 1;
				}
				else
					r = mid - 1;
			}
			//替换a[i]
			stack[l] = a[i].h;
			dp[i] = l;
		}
		if (dp[i]>maxx)
			maxx = dp[i];
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &a[i].w, &a[i].h);
		}
		sort(a + 1, a + n + 1, cmp);
		LIS();
		printf("%d\n", maxx);
	}
	return 0;
}
/*
10
4
30 10 20 13 20 14 20 15//此样例可以解释为什么选择一个升序，一个降序排列
4
10 10 20 10 20 10 30 25//此样例决定了求的最长上升子序列包括相等情况
4
10 15 20 10 20 30 30 25
3
20 30 40 50 30 40
4
20 30 10 10 30 20 40 50
3
10 30 20 20 30 10
4
10 10 20 30 40 50 39 51
*/
