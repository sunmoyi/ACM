#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

unsigned long long F[100];

int main(void)
{
	F[1] = 2, F[2] = 3, F[3] = 5;
	for (int i = 4; i < 100; i++)
	{
		F[i] = F[i - 1] + F[i - 2] - F[i - 3];
		printf("%d %llu\n", i, F[i]);
	}
	return 0;
}