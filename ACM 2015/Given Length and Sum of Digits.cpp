#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
using namespace std;

int m, s;
char s1[maxn];
char s2[maxn];

void read(void)
{
	scanf("%d %d", &m, &s);
}

void solve(void)
{
	if (m == 1 && s == 0)
	{
		printf("0 0\n");
		return;
	}
	if (s < 1 || s > m * 9)
	{
		printf("-1 -1\n");
		return;
	}
	s1[0] = max(s - (m - 1) * 9, 1) + '0';
	int now = s - s1[0] + '0';
	for (int i = m - 1; i >= 1; i--)
	{
		if (now > 9)
			s1[i] = '9', now -= 9;
		else
			s1[i] = '0' + now, now = 0;
	}
	printf("%s ", s1);

	now = s;
	for (int i = 0; i < m; i++)
	{
		if (now > 9)
			s2[i] = '9', now -= 9;
		else
			s2[i] = '0' + now, now = 0;
	}
	printf("%s\n", s2);
}

int main(void)
{
	read();
	solve();

	return 0;
}