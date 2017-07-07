#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t;
int a[5];
int b[5];
char str1[100], str2[100];
bool flag = true;

int main(void)
{
	while (scanf("%d", &t) != EOF)
	{
		for (int kk = 1; kk <= t; ++kk)
		{
			flag = true;
			getchar();
			scanf("%s", str1);
			scanf("%s", str2);
			int i = 0;
			memset(a, 0, sizeof(a));
			memset(b, 0, sizeof(b));
			int s = 1;
			while (i < strlen(str1))
			{
				while (str1[i] != '.' && str1[i] != 0)
				{
					a[s] *= 10;
					a[s] += str1[i] - '0';
					i++;
				}
				i++;
				s++;
			}
			s = 1;
			i = 0;
			while (i < strlen(str2))
			{
				while (str2[i] != '.' && str2[i] != 0)
				{
					b[s] *= 2;
					b[s] += str2[i] - '0';
					i++;
				}
				i++;
				s++;
			}

			for (int i = 1; i <= 4; i++)
				if (a[i] != b[i] || a[i] > 255 || a[i] < 0)
					flag = false;
			if (!flag)
				printf("Case %d: No\n", kk);
			else
				printf("Case %d: Yes\n", kk);
		}
	}
	return 0;
}