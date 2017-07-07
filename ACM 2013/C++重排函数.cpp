#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n, p[10];
	scanf_s("%d", &n);
	for (int i = 0; i < 10; i++)
		scanf_s("%d", &p[i]);
	sort(p, p + n);
	do{
		for (int i = 0; i < n; i++)
			printf("%d ", p[i]);
		printf("\n");
	} while (next_permutation(p, p + n));
	return 0;
}