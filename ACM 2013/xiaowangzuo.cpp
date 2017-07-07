/*#include <stdio.h>
struct bu{
	int people;
	int wide;
}a[10000];
int dis[10000], wi, n, count1;
void insert1(int num)
{
	int i, j, k;
	bu ntemp;
	for (i = 0; i<num; i++)
	{
		ntemp = a[i];
		for (j = 0; j <= i; j++)
		{
			if (a[i].people>ntemp.people)
			{
				for (k = i; k>j; k--)
					a[k] = a[k - 1];
				a[j] = ntemp;
				break;
			}
		}
	}
}

int main()
{
	while (scanf_s("%d%d", &n, &wi) != EOF)
	{
		count1 = 0;
		for (int i = 0; i<n; i++)
			scanf_s("%d%d", &a[i].people, &a[i].wide);
		insert1(n);
		for (int i = 1; i<n; i++)
		{
			dis[i] = a[i].people - a[i - 1].people - ((a[i].wide + a[i - 1].wide) / 2);
			if (dis[i]>wi)
				count1 += 2;
			else if (dis[i] == wi)
				count1++;
		}
		printf("%d\n", count1 + 2);
	}
	return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int a;
} house;

int cmp(const void *a, const void *b)
{
	return ((house *)a)->x - ((house *)b)->x;
}

int main()
{
	int n, t;
	//  freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	while (scanf("%d %d", &n, &t) != EOF){
		int sum = 2, i;
		house h[1000];
		for (i = 0; i < n; i++) scanf("%d %d", &h[i].x, &h[i].a);

		qsort(h, n, sizeof(house), cmp);

		for (i = 0; i < n - 1; i++) {
			int f = 0;

			if (h[i].x + h[i].a / 2.0 + t <= h[i + 1].x - h[i + 1].a / 2.0) {
				sum++; f++;
			}

			if (h[i + 1].x - h[i + 1].a / 2.0 - t >= h[i].x + h[i].a / 2.0) {
				sum++; f++;
			}

			if (f == 2) {
				if (h[i].x + h[i].a / 2.0 + t == h[i + 1].x - h[i + 1].a / 2.0) {
					sum--;
				}
			}
		}

		printf("%d\n", sum);
	}
	return 0;
}

