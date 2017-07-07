#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int num[maxn];
int minn = 0x3f3f3f3f;

int main (void)
{
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	while (scanf("%d", &n) != EOF)
	{
		memset(num, 0, sizeof(num));
		int i, res = 0x3f3f3f3f;
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);

		sort(num, num + n);

		for (int i = 0; i < minn; i++)
		{
			int p = upper_bound(num, num + n, num[i] * 2) - num;
			minn = min(n - p + i, minn);
		}
		printf("%d\n", minn);
	}
	return 0;
}