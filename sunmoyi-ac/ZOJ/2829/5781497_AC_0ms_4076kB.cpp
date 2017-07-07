#include<cstdio>

using namespace  std;

int num[1000100];
int a = 1, b = 1, ans;

int main(void)
{
	for (int i = 1; i <= 100010; i++)
	{
		int aa = a * 3;
		int bb = b * 5;
		if (aa > bb)
		{
			num[i] = bb;
			++b;
		}
		else if (aa < bb)
		{
			num[i] = aa;
			++a;
		}
		else
		{
			num[i] = aa;
			++a;
			++b;
		}
	}
	while (scanf("%d", &ans) != EOF)
	{
		printf("%d\n", num[ans]);
	}
	return 0;
}