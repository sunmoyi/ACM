#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int mod = 1000000007;
int ans, maxx, num[100005], ss[100005];

int main(void)
{
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			bool flag = false;
			scanf("%d", &maxx);
			for (int i = 1; i < maxx; i++)
			{
				scanf("%d", &num[i]);
				ss[i] = 26;
				if (num[i - 1] < num[i] && i != 1)
					flag = true;
			}
			if (flag)
			{
				printf("0\n");
				break;
			}
			ss[maxx] = 26;
			for (int i = 1; i < maxx; i++)
			{
				int j, k;
				for (j = i + 1, k = 1; k <= num[i]; k++)
				{
					ss[j++] = 1;
				}
				ss[j] = 25;
			}
			int kk = 1;
			for (int i = 1; i <= maxx; i++)
			{
				kk = (kk * ss[i]) % 1000000007;
			}
			printf("%d\n", kk);
		}
	}
	return 0;
}