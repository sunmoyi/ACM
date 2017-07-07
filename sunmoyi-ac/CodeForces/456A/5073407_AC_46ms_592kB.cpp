#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct k{
	int prince;
	int quality;
}a[100005];

bool cmp(k a, k b)
{
	if (a.prince == b.prince)
		return a.quality < b.quality;
	return a.prince < b.prince;
}
int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d %d", &a[i].prince, &a[i].quality);
		sort(a, a + n, cmp);
		int flag = 1;
		for (int i = 0; i < n - 1; i++)
			if (a[i].quality > a[i + 1].quality)
			{
				flag = 0;
				break;
			}
		if (flag)
			printf("Poor Alex\n");
		else
			printf("Happy Alex\n");
	}
	return 0;
}