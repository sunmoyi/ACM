#include<stdio.h>
#include<string.h>

int map[205];
int n, m, start, end, maxx;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	while (scanf_s("%d", &n) != EOF)
	{
		while (n--)
		{
			scanf_s("%d", &m);
			memset(map, 0, sizeof(map));
			while (m--)
			{
				scanf_s("%d %d", &start, &end);
				if (start > end)
					swap(&start, &end);
				for (int i = (start + 1) / 2; i <= (end + 1) / 2; i++)
					map[i]++;
			}
			maxx = 0;
			for (int i = 1; i <= 203; i++)
				if (map[i] > maxx)
					maxx = map[i];
			printf("%d\n", maxx * 10);
		}
	}
	return 0;
}