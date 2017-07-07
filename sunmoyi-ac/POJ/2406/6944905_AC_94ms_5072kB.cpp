#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000000

using namespace std;

char str[maxn];
int nextt[maxn], len;

void make_next()
{
	int i = 0, j = -1;
	nextt[0] = -1;
	while (i < len)
	{
		if (j == -1 || str[i] == str[j])
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
	while (scanf("%s", str) != EOF && str[0] != '.')
	{
		len = strlen(str);
		make_next();
		int rate = len - nextt[len];
		if (len % rate == 0)
			printf("%d\n", len / rate);
		else
			printf("1\n");
	}
	return 0;
}