#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 40

using namespace std;

char fo[maxn], la[maxn], dic[maxn];
int res[maxn];
int n, m;
int sum = 0;

void dfs(char a, int num)
{
	if (num == n - 1)
	{
		sum += res[a - 'a'];
		return;
	}
	
	for (int i = 1; i <= m; i++)
		if (dic[i] == a)
			dfs(fo[i], num + 1);
}

int main(void)
{
	scanf("%d %d", &n, &m);
	memset(res, 0, sizeof(res));
	for (int i = 1; i <= m; i++)
	{
		getchar();
		scanf("%c%c %c", &fo[i], &la[i], &dic[i]);
		res[dic[i] - 'a']++;
	}
	dfs('a', 1);
	printf("%d\n", sum);
	return 0;
}