#include<cstdio>
#include<algorithm>
using namespace std;
int a[100000];
int main(void)
{

	int i, j, k, l, t, time;
	while (scanf_s("%d", &t))
	{
		if (!t)
			break;
		for (k = 1; k <= t; k++)
			scanf_s("%d", &a[k]);
		sort(a + 1, a + t + 1);
		int flag = 0;
		int cnt = 0;
		for (k = 1; k <= t; k++)
		{
			if (a[k] != flag)
			{
				cnt++;
				flag = a[k];
			}
		}
		time = flag * 10 + cnt * 5;
		printf("%d\n", time);
	}
	return 0;
}