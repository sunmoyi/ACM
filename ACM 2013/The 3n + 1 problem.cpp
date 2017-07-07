#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b; 
	*b = temp;
}

int main(void)
{
	int a;
	int b;
	int deep, maxx;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		int aa = a;
		int bb = b;
		if (b < a)
			swap(&aa, &bb);
		maxx = 0;
		for (int i = aa; i <= bb; i++)
		{
			deep = 1;
			int t = i;
			while (t > 1)
			{
				deep++;
				if (t % 2 == 1)
					t = 3 * t + 1;
				else
					t /= 2;
			}
			if (maxx < deep)
				maxx = deep;
		}
		printf("%d %d %d\n", a, b, maxx);
	}
	return 0;
}