#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int sum[10];

int find(int t)
{
	int kk[10], k = 0;
	while (t > 0)
	{
		kk[k++] = t % 10;
		t /= 10;
	}
	int summ = 0;
	for (int i = 0; i < k; i++)
		summ += sum[kk[i]];

	return summ;
}

int main(void)
{
	sum[0] = 6;
	sum[1] = 2;
	sum[2] = 5;
	sum[3] = 5;
	sum[4] = 4;
	sum[5] = 5;
	sum[6] = 6;
	sum[7] = 3;
	sum[8] = 7;
	sum[9] = 6;
	
	int a, b;
	while (scanf_s("%d %d", &a, &b) != EOF)
	{
		long long summ = 0;
		for (int i = a; i <= b; i++)
			summ += find(i);
		printf("%lld\n", summ);
	}
	return 0;
}