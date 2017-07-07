#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[10][5] = { { 0 },{ 1 },{ 6,2,4,8 },{ 1,3,9,7 },{ 6,4 },{ 5 },{ 6 },{ 1,7,9,3 },{ 6,8,4,2 },{ 1,9 } };

int main(void)
{
	int  a, b;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		a = a % 10;
		if (a == 0 || a == 1 || a == 5 || a == 6)
			printf("%d\n", a);
		else if (a == 4 || a == 9)
			printf("%d\n", num[a][b % 2]);
		else
			printf("%d\n", num[a][b % 4]);
	}
	return 0;
}