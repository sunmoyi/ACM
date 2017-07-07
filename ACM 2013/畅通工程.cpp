#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int father[1050];
int t[1050];

int find(int x)
{
	int far = x;
	while (far != father[far])
		far = father[far];

	int i = x;
	while (father[i] != far)
	{
		int temp = father[i];
		father[i] = far;
		i = temp;
	}
	return far;
}

void mix(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx != fy)
	{
		father[fy] = fx;
	}
}

int main(void)
{
	int N, M, a, b, i, j, ans;
	while (scanf("%d%d", &N, &M) && N)
	{
		for (i = 1; i <= N; i++)          
			father[i] = i;

		for (i = 1; i <= M; i++)             
		{
			scanf("%d%d", &a, &b);
			mix(a, b);
		}


		memset(t, 0, sizeof(t));
		for (i = 1; i <= N; i++)          
		{
			t[find(i)] = 1;
		}
		for (ans = 0, i = 1; i <= N; i++)
			if (t[i])
				ans++;

		printf("%d\n", ans - 1);

	}
	return 0;
}