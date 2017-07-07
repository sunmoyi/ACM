#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[10];
int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1} };

bool check(int x, int y)
{
	if (x <= 0 || x > 8 || y <= 0 || y > 8)
		return false;
	return true;
}

int main (void)
{
	while (scanf("%s", str) != EOF)
	{
		int ans = 0;
		int ans1 = str[0] - 'a' + 1;
		int ans2 = str[1] - '0';
		for (int i = 0; i < 8; i++)
		{
			int xx = ans1 + dir[i][0];
			int yy = ans2 + dir[i][1];
			if (check(xx, yy))
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}