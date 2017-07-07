#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 4000000

using namespace std;

char T[maxn];
int nextt[maxn];
int len;
int ans[maxn], k;

void make_next()
{
	int i = 0, j = -1;
	nextt[0] = -1;
	while (i < len)
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
	while (scanf("%s", &T) != EOF)
	{
		k = 0;
		len = strlen(T);
		make_next();
		for (int i = len; i != 0; )
		{
			ans[k++] = nextt[i];
			i = nextt[i];
		}
		for (int i = k - 2; i >= 0; i--)
			printf("%d ", ans[i]);
		printf("%d\n", len);
	}
	return 0;
}