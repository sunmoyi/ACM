#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100

using namespace std;

int num[maxn];
int n, m;

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &num[i]);
		}

		sort(num + 1, num + m + 1);

		int minn = 0x3f3f3f3f;
		for (int i = 1; i + n - 1<= m; i++)
			minn = min(minn, num[i + n - 1] - num[i]);
		printf("%d\n", minn);
	}
	return 0;
}