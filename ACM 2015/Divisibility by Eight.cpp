#include <iostream>  
#include <stdio.h>  
#include <string.h>  
#include <stack>  
#include <queue>  
#include <map>  
#include <set>  
#include <vector>  
#include <math.h>  
#include <bitset>  
#include <algorithm>  
#include <climits>  
using namespace std;

#define LS 2*i  
#define RS 2*i+1  
#define UP(i,x,y) for(i=x;i<=y;i++)  
#define DOWN(i,x,y) for(i=x;i>=y;i--)  
#define MEM(a,x) memset(a,x,sizeof(a))  
#define W(a) while(a)  
#define gcd(a,b) __gcd(a,b)  
#define LL long long  
#define N 2000005  
#define MOD 1000000007  
#define INF 0x3f3f3f3f  
#define EXP 1e-8  

char str[1005];

int main()
{
	while (~scanf("%s", str + 2))
	{
		str[0] = str[1] = '0';
		int len = strlen(str), s;
		int i, j, k, flag = 0;
		for (i = 0; i<len - 2; i++)
		{
			if (flag) break;
			for (j = i + 1; j<len - 1; j++)
			{
				if (flag) break;
				for (k = j + 1; k<len; k++)
				{
					s = (str[i] - '0') * 100 + (str[j] - '0') * 10 + str[k] - '0';
					if (s % 8 == 0)
					{
						flag = 1;
						break;
					}
				}
			}
		}
		if (flag)
			printf("YES\n%d\n", s);
		else
			printf("NO\n" );
	}

	return 0;
}