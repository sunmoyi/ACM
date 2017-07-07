#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[30];
int n, m, k;

int goo(int p, int d, int t)
{
	while (t--)
	{
		do{
			p = (p + d + n - 1) % n + 1;
		} while (num[p] == 0);
	}
	return p;
}

int main(void)
{
	while (scanf("%d %d %d", &n, &m, &k) != EOF && (n + m + k))
	{
		for (int i = 1; i <= 29; i++)
			num[i] = i;
		int left = n;
		int p1 = n;
		int p2 = 1; 
		while (left)
		{
			p1 = goo(p1, 1, m);
			p2 = goo(p2, -1, k);
			left--;
			printf("%3d", p1);
			if(p1 != p2)
			{
				left--;
				printf("%3d", p2);
			}
			num[p1] = num[p2] = 0;
			if (left)
				printf(",");
		}
		printf("\n");
	}
	return 0;
}