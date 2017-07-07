#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000100

using namespace std;

char T[maxn], p[maxn];
int nextt[maxn];
int len1, len2;

void get_next()
{
	int i = 0, j = -1;
	nextt[0] = -1;
	while (i < len1)
	{
		if (j == -1 || T[i] == T[j])
		{
			i++;
			j++;
			nextt[i] = j;
		}
		else
			j = nextt[j];
	}
}

int main(void)
{
	int t;
	while (scanf("%d", &t) != EOF)
	{
		getchar();
		while (t--)
		{
			for (int i = 1; i <= t; i++)
				scanf("%s", T);
			len1 = strlen(T);
			get_next();
			int rate = len1 - nextt[len1];
			if (len1 % rate == 0 && (len1 / rate) >= 2)
				printf("0\n");
			else
				printf("%d\n", rate - len1 % rate);
		}
	}
	return 0;
}