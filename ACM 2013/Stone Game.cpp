/********************************
*
*HDU 1729
*
*数据
*3 → 3个桶
*2 0 → 桶的上限2 现有0
*3 3 → 桶的上限3 现有3
*6 2 → 桶的上限6 现有2 每次增加的数量最多是 现有的平方 如现在做多增加2的平方 = 4
**********************************/

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int sg(int s, int c)
{
	int q = sqrt(double(s));
	while (q + q * q >= s)
		q--;
	if (c > q)
		return (s - c);
	else
		return sg(q, c);
}

int main(void)
{
	int ans, t = 0;;
	while (scanf_s("%d", &ans) != EOF && ans)
	{
		int s, c;
		printf("Case %d:\n", ++t);
		int tt = 0;
		while (ans--)
		{
			scanf_s("%d %d", &s, &c);
			tt ^= sg(s, c);
		}
		if (tt)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}