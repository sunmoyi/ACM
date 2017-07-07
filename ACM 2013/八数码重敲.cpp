#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int bfs(int *a, int *goal);
int viss(int *a);
int vis[1000000] = { 0 };
void vi();
int visss[9] = { 0 };
int ns[4][2] = { { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 } };
int from[9], goal[9];
int main(void)
{
	for (int i = 0; i < 9; i++)
		scanf_s("%d", &from[i]);
	for (int i = 0; i < 9; i++)
		scanf_s("%d", &goal[i]);
	int ans = bfs(from, goal);
	printf("%d", ans);
	return 0;
}
void vi()
{
	visss[0] = 1;
	for (int i = 1; i < 9; i++)
		vis[i] = vis[i - 1] * 9;
}
int viss(int *a)
{
	long long sum = 0;
	for (int i = 0; i < 9; i++)
		sum += a[i] * visss[i];
	if (vis[sum] == 1)
		return 0;
	else
		return vis[sum] = 1;
}
int bfs(int *a, int *goal)
{
	queue <int *> q;
	int k = 0;
	q.push(a);
	k = memcmp(q.front(), goal, sizeof(36));
	while (memcmp(q.front(), goal, sizeof(from)) != 0 && !q.empty())
	{
		int *b;
		b = q.front();
		int z;
		for (z = 0; z < 9; z++)
			if (b[z] == 0)
				break;
		int x = z / 3;
		int y = z % 3;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + ns[i][0];
			int ny = y + ns[i][1];
			int nz = nx * 3 + ny;
			if (nx < 3 && nx >= 0 && ny < 3 && ny >= 0)
			{
				int temp = b[z];
				b[z] = b[nz];
				b[nz] = temp;
				q.push(b);
			}
		}
		q.pop();
		k++;
	}
	if (k == 0)
		return 0;
	for (int i = 1)
}