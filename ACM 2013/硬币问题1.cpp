#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>

using namespace std;

int x;
int k;
bool win[100000];
int a[100000];

void Bash()
{
	win[0] = false;

	for (int i = 1; i <= x; i++)
	{
		win[i] = false;
		for (int j = 0; j < k; i++)
			win[i] |= (a[j] <= i && !win[i - a[j]]); // |=   真真为真 真假为真  假假为假
	}
}

int main(void)
{
	while (scanf("%d %d", &x, &k) != EOF)
	{
		for (int i = 0; i < k; i++)
			scanf("%d", &a[i]);
		sort(a, a + k);
		memset(win, 0, sizeof(a));
		Bash();
		if (win[x])
			printf("Alicce!\n");
		else
			printf("Bob!\n");
	}
	return 0;
}