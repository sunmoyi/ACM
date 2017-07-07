#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node {
	char name[20];
	int starttime;
	int endtime;
}num[1000000];

bool cmp1(node a, node b)
{
	return a.starttime < b.starttime;
}

bool cmp2(node a, node b)
{
	return a.endtime > b.endtime;
}

int main(void)
{
	int n, m;
	int a, b, c, d, e, f;
	while (scanf("%d", &n) != EOF)
	{
		while (n--)
		{
			scanf("%d", &m);
			for (int i = 1; i <= m; i++)
			{
				scanf("%s %d:%d:%d %d:%d:%d", num[i].name, &a, &b, &c, &d, &e, &f);
				num[i].starttime = a * 10000 + b * 100 + c;
				num[i].endtime = d * 10000 + e * 100 + f;
			}
			sort(num + 1, num + m + 1, cmp1);
			printf("%s ", num[1].name);
			sort(num + 1, num + m + 1, cmp2);
			printf("%s\n", num[1].name);
		}
	}
	return 0;
}