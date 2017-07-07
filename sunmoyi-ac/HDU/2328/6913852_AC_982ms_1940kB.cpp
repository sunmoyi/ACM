#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 4040
#define maxm 210

using namespace std;

int n, nextt[maxn];
char str[maxn][maxm];

void make_next(char *P)
{
	int i = 0, j = -1;
	nextt[0] = -1;
	int len = strlen(P);
	while (i < len)
	{
		if (j == -1 || P[i] == P[j])
		{
			i++;
			j++;
			nextt[i] = j;
		}
		else
			j = nextt[j];
	}
}

bool KMP(char *T, char *P)
{
	int i = 0, j = 0;
	int len1 = strlen(T), len2 = strlen(P);
	while (i < len1 && j < len2)
	{
		if (T[i] == P[j] || j == -1)
			i++, j++;
		else
			j = nextt[j];
		if (j == len2)
			return true;
	}
	return false;
}

int main(void)
{
	while (scanf("%d", &n) != EOF && n)
	{
		getchar();
		for (int i = 1; i <= n; i++)
			scanf("%s", str[i]);

		//sort(str + 1, str + n + 1, cmp);

		char ans[maxn], temp[maxn];
		int len = strlen(str[1]);
		int maxx = -1;
		for (int i = 0; i < len; i++)
		{
			memset(temp, 0, sizeof(temp));
			int pos = 0;
			for (int j = i; j < len; j++)
			{
				temp[pos++] = str[1][j];
				make_next(temp);

				bool flag = true;
				for (int k = 2; k <= n; k++)
				{
					if (KMP(str[k], temp) == false)
					{
						flag = false;
						break;
					}
				}
				if (flag && maxx < pos)
				{
					maxx = pos;
					memcpy(ans, temp, sizeof(temp));
				}
				else if (flag && maxx == pos && strcmp(ans, temp) > 0)
					memcpy(ans, temp, sizeof(temp));
			}
		}
		if (maxx != -1)
			printf("%s\n", ans);
		else
			printf("IDENTITY LOST\n");
	}
	return 0;
}