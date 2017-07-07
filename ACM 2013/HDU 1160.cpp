#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
	int wei;
	int spe;
	int num;
}a[1010];

int l[1010], pro[1010], ans[1010];

bool cmp(node a, node b)
{
	if (a.wei != b.wei)
		return a.wei < b.wei;
	else
		return a.spe > b.spe;
}

int main(void)
{
	int num = 1;
	while (scanf_s("%d %d", &a[num].wei, &a[num].spe) != EOF)
	{
		a[num].num = num++;
	}

	sort(a + 1, a + num, cmp);

	for (int i = 1; i < num; i++)
	{
		l[i] = 1;
		pro[i] = 0;
	}

	for (int i = 1; i < num; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[i].wei > a[j].wei && a[i].spe < a[j].spe && l[i] < l[j] + 1)
			{
				l[i] = l[j] + 1;
				pro[i] = j;
			}
		}
	}

	int end;
	int maxx = -1;
	for (int i = 2; i < num; i++)
	{
		if (l[i] > maxx)
		{
			maxx = l[i];
			end = i;
		}
	}

	for (int i = 1; i <= maxx; i++)
	{
		ans[i] = end;
		end = pro[end];
	}

	printf("%d\n", maxx);
	for (int i = maxx; i >= 1; i--)
	{
		printf("%d\n", a[ans[i]].num);
	}
	return 0;
}