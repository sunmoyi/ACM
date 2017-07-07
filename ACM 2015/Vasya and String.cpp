#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

char str[maxn];
int num[maxn];
int k, sum;

int main(void)
{
	while (scanf("%d %d", &sum, &k) != EOF)
	{
		getchar();
		scanf("%s", str);
		int top = 0, tt = 0;
		int bug = 0;
		for (int i = 0; i < sum; i++)
		{
			if (str[i] == 'a')
			{
				tt++;
				continue;
			}
			else
			{
				bug++;
				num[top++] = tt;
				tt = 0;
			}
		}
		num[top++] = tt;
		int maxx1 = 0, ans = 0;;
		for (int i = 0; i <= k; i++)
			maxx1 += num[i];
		ans = maxx1;
		for (int i = k + 1; i < top; i++)
		{
			ans -= num[i - k - 1];
			ans += num[i];
			maxx1 = max(maxx1, ans);
		}

		top = 0, tt = 0;
		for (int i = 0; i < sum; i++)
		{
			if (str[i] == 'b')
			{
				tt++;
				continue;
			}
			else
			{
				//bug++;
				num[top++] = tt;
				tt = 0;
			}
		}
		num[top++] = tt;
		int maxx2 = 0;
		for (int i = 0; i <= k; i++)
			maxx2 += num[i];
		ans = maxx2;
		for (int i = k + 1; i < top; i++)
		{
			ans -= num[i - k - 1];
			ans += num[i];
			maxx2 = max(maxx2, ans);
		}



		printf("%d\n", min(max(maxx1, maxx2) + min(k, bug), sum));
	}
	return 0;
}