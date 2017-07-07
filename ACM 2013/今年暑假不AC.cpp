#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
struct show
{
	int s;
	int e;
}pro[110];
bool cmp(show a, show b)
{
	return a.e<b.e;
}
int main()
{
	while (scanf("%d", &n) != EOF&&n)
	{
		int cnt = 1, i;
		memset(pro, 0, sizeof(pro));
		for (i = 0; i<n; i++)
		{
			scanf("%d%d", &pro[i].s, &pro[i].e);
		}
		sort(pro, pro + n, cmp);
		int tmp = pro[0].e;
		for (i = 1; i<n; i++)
		{
			if (pro[i].s >= tmp)
			{
				cnt++;
				tmp = pro[i].e;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}