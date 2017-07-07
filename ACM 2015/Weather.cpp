#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int num[maxn], sum;
int up[maxn], down[maxn];
int minn = 0x3f3f3f3f;

int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (scanf("%d", &sum) != EOF)
	{
		minn = 0x3f3f3f3f;
		for (int i = 1; i <= sum; i++)
			scanf("%d", &num[i]);

		for (int i = 1; i < sum; i++)
			up[i] = (num[i] >= 0) ? up[i - 1] + 1 : up[i - 1];
		for (int i = sum; i > 1; i--)
			down[i] = (num[i] <= 0) ? down[i + 1] + 1 : down[i + 1];

		minn = min(minn, up[1] + down[2]);
		minn = min(minn, up[sum - 1] + down[sum]);
		for (int i = 2; i < sum; i++)
		{
			if (num[i] == 0)
				minn = min(minn, up[i - 1] + down[i + 1] + 1);
			else
			{
				int temp = min(up[i - 1] + down[i], up[i] + down[i + 1]);
				minn = min(minn, temp);
			}
		}
		
		printf("%d\n", minn);
	}
	return 0;
}