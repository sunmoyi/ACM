#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000010
using namespace std;

char T[maxn];
int nextt[maxn];
int len;
int len1, len2;

void make_next()
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

int main (void)
{
	int icase = 1;
	while (scanf("%d", &len1) != EOF && len1)
	{
		getchar();
		scanf("%s", T);
		make_next();
		printf("Test case #%d\n", icase++);
		for (int i = 2; i <= len1; i++)
		{
			int rate = i - nextt[i];
			if (i % rate == 0 && i > rate)
				printf("%d %d\n", i, i / rate);
		}
		printf("\n");
	}
	return 0;
}