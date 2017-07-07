#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int par[100005];
int rankk[100005];
int num[100005];
int flag = 1;
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
	if (x == y)
	{
		flag = 0;
		return;
	}

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
	int a, b, cnt = 0;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		memset(num, 0, sizeof(num));
		init(100005);
		flag = 1;
		if (a == -1 && b == -1)
			break;
		if (a == 0 && b == 0)
			printf("Yes\n");
		unionn(a, b);
		num[a] = num[b] = 1;
		do{
			scanf("%d %d", &a, &b);
			if (a == 0 && b == 0)
				break;
			unionn(a, b);
			num[a] = num[b] = 1;
		} while (1);
		int k = 0;
		for (int i = 1; i < 100005; i++)
		{
			if (num[i] && par[i] == i)
				k++;
			if (k > 1)
				flag = 0;
		}
		if (flag == 1)
			printf("Case %d is a tree.\n", ++cnt);
		else
			printf("Case %d is not a tree.\n", ++cnt);
	}
	return 0;
}