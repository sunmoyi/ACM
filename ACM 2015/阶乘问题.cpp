#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans;

int main(void)
{
	long long temp = 1;
	while (scanf("%d", &ans) != EOF)
	{
		for (int i = 2; i <= ans; i++)
		{
			temp *= i;
			while (!(temp % 10))
			{
				temp /= 10;
			}
			temp %= 100;	
		}
		printf("%lld\n", temp % 10);
	}
	return 0;
}

/*
2 2
3 6
4 4
5 2
6 2
7 4
8 2
9 8
10 8
11 8
12 6
13 8
14 2
15 8
16 8
17 6
18 8
19 2
20 4
21 4
22 8
23 4


*/