#include<cstdio>
#include<cstring>
#include<algorithm>
#pragma comment(linker, "/STACK:1024000000,1024000000")/*windowns编译环境专用 - - */
using namespace std;

int f[15], sg[1005], n;

int mex(int x)
{
	int a[1001] = { 0 };
	for (int i = 0; i <= 10; i++)
	{
		if (x - f[i] < 0)
			break;
		if (sg[x - f[i]] == -1)
			sg[x - f[i]] = mex(x - f[i]);
		a[sg[x - f[i]]] = 1;
	}
	for (int i = 0; i <= 10; i++)
		if (!a[i])
			return i;
}

int main(void)
{
	while (scanf_s("%d", &n) != EOF)
	{
		memset(sg, -1, sizeof(sg));
		f[0] = 1;
		sg[0] = 0;
		for (int i = 1; i <= 10; i++)
		{
			f[i] = f[i - 1] * 2;
		}

		int ans = 0;
		if (sg[n] == -1)
			sg[n] = mex(n);
		ans ^= sg[n];
		if (ans == 0)
			printf("Cici\n");
		else
			printf("Kiki\n");
	}
	return 0;
}
/*由以上函数小额打表可得：  3的倍数为cici胜  （数字太大会爆栈）*/