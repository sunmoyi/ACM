#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char s[111111111];

int check(long long a, long long b)
{
	int ret = 0;
	for (int i = 0; i < b; i++)
		ret = (ret * 10 + s[i] - '0') % a;
	return ret % a == 0;
}

int main(void)
{
	int icase = 1;

	while (scanf("%s", s) != EOF)
	{
		printf("Case #%d: ", icase++);
		if (check(137, strlen(s)) && check(73, strlen(s)))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

/*
aa   ab
ab   ba
aa   bb



*/