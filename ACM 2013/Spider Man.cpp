#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

long long num[maxn];
int sum;

int main(void)
{
	while(scanf("%d" ,&sum) != EOF)
	{
		bool flag = false;
		for (int i = 1; i <= sum; i++)
		{
			scanf("%lld", &num[i]);
			if (num[i] == 1)
				;
			else if (num[i] % 2 == 0)
				flag = (!flag);
			
			if (flag)
				printf("1\n");
			else
				printf("2\n");
		}
	}
	return 0;
}