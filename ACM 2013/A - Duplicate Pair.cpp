#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool k[10000000];
int maxx, ans, a;

int main(void)
{
	while (scanf("%d", &maxx) != EOF)
	{
		memset(k, 0, sizeof(k));
		for (int i = 1; i <= maxx; i++)
		{
			scanf("%d", &a);
			if (k[a] == true)
				ans = a;
			else
				k[a] = true;
		}
		printf("%d\n", ans);
	}
	return 0;
}