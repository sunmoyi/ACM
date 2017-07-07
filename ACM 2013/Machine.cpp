#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<iostream>

using namespace std;

int ans;
unsigned __int64 kk, k;
stack<int>S;

int num[100];

int main(void)
{
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			memset(num, 0, sizeof(num));
			int i = 0;
			cin >> k >> kk;
			while (kk > 0)
			{
				num[i] = kk % 3;
				kk /= 3;
				i++;
			}
			for (int i = k - 1; i >= 0; i--)
			{
				if (num[i] == 1)
					printf("G");
				else if (num[i] == 2)
					printf("B");
				else
					printf("R");
			}
			printf("\n");
		}
	}
	return 0;
}