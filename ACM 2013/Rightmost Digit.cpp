#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int c[10][4] = { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 6, 2, 4, 8 }, { 1, 3, 9, 7 }, { 6, 4, 6, 4 }, { 5, 5, 5, 5 }, { 6, 6, 6, 6 }, { 1, 7, 9, 3 }, { 6, 8, 4, 2 }, { 1, 9, 1, 9 } };
int main(void)
{
	int T;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			int a;
			scanf("%d", &a);
			printf("%d\n", c[a % 10][a % 4]);
		}
	}
	return 0;
}