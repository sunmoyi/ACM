
#include<iostream>
#include<cstring>
using namespace std;

int N, ans, digit, flag, full[9];

void div(int m)
{
	while (m)
	{
		if (m % 10 != 0)
			full[m % 10 - 1] = 1;
		m /= 10;
		digit++;
	}
}

bool check(int *f)
{
	int j;
	for (j = 0; j<9; j++)
		if (!f[j])
			return false;
	return true;
}

void  DFS(int a, int b, int c)
{
	digit = 0;
	flag = 0;
	div(a);
	div(b);
	div(c);
	if (digit>9) { memset(full, 0, sizeof(full)); return; }
	if (check(full)) { ans++; memset(full, 0, sizeof(full)); }
	else memset(full, 0, sizeof(full));
	DFS(a, (c + 1)*b / c, c + 1);
	return;
}

int main()
{
	int i;
	while (cin >> N)
	{
		ans = 0;
		memset(full, 0, sizeof(full));
		for (i = 2; i<N - 1; i++)
			DFS(i, N - i, 1);
		cout << ans << endl;
	}
	return 0;
}