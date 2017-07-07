/*******************************************************
 *题目： 斐波那契数列 
 *F[0] = 7, F[1] = 11, F[2] = 18
 *
 *输入n求第F[n]能否被3整除
 *
 *********************************************************/

#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn = 100000000;
using namespace std;

int num[maxn]; 
int ans;

void solve(void)
{
	num[0] = 7; num[1] = 11;
	for (int i = 2; i <= maxn; i++)
		num[i] = (num[i - 1] + num[i - 2]) % 3;
}

int main(void)
{
	solve();
	while (scanf("%d", &ans) != EOF)
	{
		if (!num[ans])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}