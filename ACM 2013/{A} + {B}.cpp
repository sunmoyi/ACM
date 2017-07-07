#include<cstdio>
#include<cstring>
#include <algorithm> 
using namespace std;
int v[1000000];
int camp(int a, int b)
{
	return a < b;
}
int main(void)
{
	int i, j, k, l, a, b;
	
	while (scanf_s("%d %d", &a, &b) != EOF)
	{
		for (i = 1; i <= a; i++)
			scanf_s("%d", &v[i]);
		for (; i <= a + b; i++)
			scanf_s("%d", &v[i]);
		sort(v + 1, v + a + b + 1, camp);
		printf("%d", v[1]);
		for (k = 2; k <= a + b; k++)
			if (v[k] != v[k - 1])
				printf(" %d", v[k]);
		printf("\n");
	}
	return 0;
}