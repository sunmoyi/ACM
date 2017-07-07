#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300010

using namespace std;

int num[maxn];

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	int l = 1, r = 1, zr = 0, ans = 0, ansl = 1, ansr = 0;
	while (r <= n)
	{
		while (r <= n && zr <= k)
		{
			if (!num[r])
			{
				if (zr == k)
					break;
				else
					zr++;
			}
			r++;
		}
		if (r - l > ans)
			ans = r - l, ansl = l, ansr = r - 1;
		while (l <= n && num[l])
			++l;
		--zr, ++l;
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
	{
		if (ansl <= i && i <= ansr)
			printf("1 ");
		else
			printf("%d ", num[i]);
	}
	printf("\n");
	return 0;
}