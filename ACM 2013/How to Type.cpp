#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans;
char str[105];
int dpa[105], dpb[105];

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		getchar();
		while (ans--)
		{
			scanf_s("%s", str + 1, 101);
			int len = strlen(str + 1);

			dpa[0] = 0;
			dpb[0] = 1;
			for (int i = 1; i <= len; i++)
			{
				if (str[i] >= 'a' && str[i] <= 'z')
				{
					dpa[i] = min(dpa[i - 1] + 1, dpb[i - 1] + 2);
					dpb[i] = min(dpa[i - 1] + 2, dpb[i - 1] + 2);
				}
				else if (str[i] >= 'A' && str[i] <= 'Z')
				{
					dpa[i] = min(dpa[i - 1] + 2, dpb[i - 1] + 2);
					dpb[i] = min(dpa[i - 1] + 2, dpb[i - 1] + 1);
				}
			}
			printf("%d\n", min(dpb[len] + 1, dpa[len]));
		}
	}
	return 0;
}