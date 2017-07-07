#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int par[100005];
int rankk[100005];
int num[100005];

void init(int n)
{
	for (int i = 1; i < n; i++)
	{
		par[i] = i;
		rankk[i] = 0;
	}
}

int find(int x)
{
	int fa = x;
	while (fa != par[fa])
		fa = par[fa];

	int i = x;
	while (par[i] != fa)
	{
		int temp = par[i];
		par[i] = fa;
		i = temp;
	}
	return fa;
}

void unionn(int x, int y)
{
	x = find(x);
	y = find(y);

	if (rankk[x] > rankk[y])
		par[y] = x;
	else
	{
		par[x] = y;
		if (rankk[x] == rankk[y])
			rankk[y]++;
	}
}

int main(void)
{
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF && a != -1 || b != -1)
	{
		memset(num, 0, sizeof(num));
		bool flag = true;
		init(100004);
		if (a == 0 && b == 0)
			printf("Yes\n");
		unionn(a, b);
		num[a] = num[b] = 1;
		do{
			scanf("%d %d", &a, &b);
			if (a == 0 && b == 0)
				break;
			if (find(a) == find(b))
				flag = false;
			unionn(a, b);
			num[a] = num[b] = 1;
		} while (1);
		int ss = 0;
		for (int i = 1; i < 100003; i++)
			if (num[i] == 1 && par[i] == i)
				ss++;
		if (ss > 1)
			flag = false;
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}