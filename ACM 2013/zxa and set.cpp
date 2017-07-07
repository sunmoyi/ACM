#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T;
int ans;
int num[1000];
__int64 maxx;

int main(void)
{
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%d", &ans);
			for (int i = 0; i < ans; i++)
			{
				scanf("%d", &num[i]);
			}

			sort(num, num + ans);

			printf("%d\n", num[ans - 1]);
		}
	}
	return 0;
}