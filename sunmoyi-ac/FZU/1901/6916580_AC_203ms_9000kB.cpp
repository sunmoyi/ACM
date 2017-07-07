#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

char S[maxn];
int nextt[maxn];
int len, ans[maxn];

void make_next()
{
	int i = 0, j = -1;
	nextt[0] = -1;
	while (i < len)
	{
		if (j == -1 || S[i] == S[j])
		{
			i++;
			j++;
			nextt[i] = j;
		}
		else
			j = nextt[j];
	}
}

int main (void)
{
	int icase = 1, T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", S);
		len = strlen(S);
		make_next();

		int k = 0;
		for (int i = len; i > 0; i = nextt[i])
			ans[k++] = len - nextt[i];

		printf("Case #%d: %d\n", icase++, k);
		printf("%d", ans[0]);
		for (int i = 1; i < k; i++)
			printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}