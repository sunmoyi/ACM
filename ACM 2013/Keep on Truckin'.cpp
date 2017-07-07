#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a, b, c;

int main(void)
{
	while (scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		if (a < 168)
		{
			printf("CRASH %d\n", a);
			break;
		}
		if (b < 168)
		{
			printf("CRASH %d\n", b);
			break;
		}
		if (c < 168)
		{
			printf("CRASH %d\n", c);
			break;
		}
		else
			printf("NO CRASH\n");
	}
	return 0;
}