#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int r, c;
int rooms[60][60];
int color[60][60];
int maxroomarea = 0, roomnum = 0;
int roomarea;

void dfs(int i, int k)
{
	if (color[i][k])
		return;
	++roomarea;
	color[i][k] = roomnum;
	if ((rooms[i][k] & 1) == 0)
		dfs(i, k - 1);
	if ((rooms[i][k] & 2) == 0)
		dfs(i - 1, k);
	if ((rooms[i][k] & 4) == 0)
		dfs(i, k + 1);
	if ((rooms[i][k] & 8) == 0)
		dfs(i + 1, k);
}

int main(void)
{
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int k = 1; k <= c; k++)
			cin >> rooms[i][k];

	memset(color, 0, sizeof(color));

	for (int i = 1; i <= r; i++)
	{
		for (int k = 1; k <= c; k++)
		{
			if (!color[i][k])
			{
				++roomnum;
				roomarea = 0;
				dfs(i, k);
				maxroomarea = max(roomarea, maxroomarea);
			}
		}
	}
	cout << roomnum << endl;
	cout << maxroomarea << endl;
	return 0;
}