#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int f[101], sg[10001], a, b, c, t, bead;

int mex(int x)
{
	int a[25] = { 0 };
	for (int i = 0; i <= 20; i++)
	{
		if (x - f[i] < 0)
			break; 
		if (sg[x - f[i]] == -1)
			sg[x - f[i]] = mex(x - f[i]);
		a[sg[x - f[i]]] = 1;
	}
	for (int i = 0; i <= 20; i++)
		if (!a[i])
			return i;
}

int main(void)
{
	f[0] = 1;
	f[1] = 2;
	for (int i = 2; i <= 20; i++)
		f[i] = f[i - 1] + f[i - 2];
	while (scanf_s("%d %d %d", &a, &b, &c) != EOF && (a + b + c))
	{
		memset(sg, -1, sizeof(sg));
		int sum = 0;
		if (sg[a] == -1)
			sg[a] = mex(a);
		if (sg[b] == -1)
			sg[b] = mex(b);
		if (sg[c] == -1)
			sg[c] = mex(c);
		sum ^= sg[a];
		sum ^= sg[b];
		sum ^= sg[c];
		if (sum == 0)
			printf("Nacci\n");
		else
			printf("Fibo\n");
	}
	return 0;
}