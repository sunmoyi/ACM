#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int ans;
int x1, x2, yy, y2, r1, r2;
double dis;

int main(void)
{
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf("%d %d %d %d %d %d", &x1, &yy, &r1, &x2, &y2, &r2);
			dis = sqrt(((x1 - x2) * (x1 - x2) + (yy - y2) * (yy - y2)) * 1.0);
			if (dis == 0 && r1 == r2)
				printf("-1\n");
			else if (dis < abs(r1 - r2))
				printf("0\n");
			else if (dis == abs(r1 - r2))
				printf("1\n");
			else if (dis < r1 + r2)
				printf("2\n");
			else if (dis == r1 + r2)
				printf("3\n");
			else
				printf("4\n");
		}
	}
	return 0;
}