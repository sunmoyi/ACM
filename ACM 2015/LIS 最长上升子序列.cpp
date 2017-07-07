#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a[1010];
int maxlen[1010];

int main(void)
{
	int N;
	scanf("%d\n", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
		maxlen[i] = 1;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j])
				maxlen[i] = max(maxlen[i], maxlen[j] + 1);
		}
	}
	printf("%d\n", *max_element(maxlen + 1, maxlen + N + 1));
	return 0;
}