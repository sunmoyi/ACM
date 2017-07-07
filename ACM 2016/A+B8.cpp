#include<stdio.h>

using namespace std;

int main (void)
{
	int N, M, Case, sum, temp;
	scanf("%d", &N);
	for (Case = 1; Case <= N; Case++)
	{
		scanf("%d", &M);
		sum = 0;
		for (int i = 1; i <= M; i++)
		{
			scanf("%d", &temp);
			sum += temp;
		}
		if (Case == N)
			printf("%d", sum);
		else
			printf("%d\n\n", sum);
	}
}