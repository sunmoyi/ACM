#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300030

using namespace std;

int que[maxn];
int application[maxn];
int num[maxn];
int beginn, endd;
int n, m;
int front;

void init(int x)
{
	beginn = 0;
	endd = 0;
	front = 0;
	memset(application, 0, sizeof(application));
	memset(num, 0, sizeof(num));
}

void add(int type)
{
	que[++endd] = type;
	num[type]++;
	front++;
	printf("%d\n", front);
}

void readx(int type)
{
	front -= num[type];
	num[type] = 0;
	application[type] = endd;
	printf("%d\n", front);
}

void readfront(int x)
{
	if (beginn >= x)
		printf("%d\n", front);
	else
	{
		for(int i = beginn + 1; i <= x; i++)
		{
			if (application[que[i]] >= i)
			{
				beginn++;
				continue;
			}
			num[que[i]]--;
			front--;
			beginn++;
		}
		printf("%d\n", front);
	}
}

int main(void)
{
	int a, b;
	scanf("%d %d", &n, &m);
	init(n + 1);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		if (a == 1)
			add(b);
		else if (a == 2)
			readx(b);
		else
			readfront(b);
	}
	return 0;
}


/*
5 10
1 1
1 2
1 1
1 3
1 1
1 1
2 1
3 5
1 2
2 2



1
2
3
4
5
6
2
0
1
0

*/