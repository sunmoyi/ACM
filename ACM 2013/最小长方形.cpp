#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
	int x;
	int y;
}a[10000000];

bool cmpx(node a, node b)
{
	return a.x < b.x;
}

bool cmpy(node a, node b)
{
	return a.y < b.y;
}

int main(void)
{
	int i = 1;
	while (scanf("%d %d", &a[1].x, &a[1].y) != EOF && a[1].x != 0 || a[1].y != 0)
	{
		i = 2;
		while (scanf("%d %d", &a[i].x, &a[i].y) && a[i].x != 0 || a[i].y != 0)
			i++;
		sort(a + 1, a + i, cmpx);
		int x1, x2, y1, y2;
		x1 = a[1].x;
		x2 = a[i - 1].x;
		sort(a + 1, a + i, cmpy);
		y1 = a[1].y;
		y2 = a[i - 1].y;
		printf("%d %d %d %d\n", x1, y1, x2, y2);
	}
	return 0;
}