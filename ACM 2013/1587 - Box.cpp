#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXD 10
using namespace std;
struct M{
	int x;
	int y;
}array[MAXD];
bool cmp(M m, M n)
{
	if (m.x > n.x)
		return true;
	if (m.x < n.x)
		return false;
	if (m.y > n.y)
		return true;
	else
		return false;
}
int solve()
{
	M arrayx[MAXD];
	int ok = 0;
	int m = 0;
	for (int i = 0; i < 6; i += 2)
	{
		if (array[i].x == array[i + 1].x && array[i].y == array[i + 1].y)
		{
			arrayx[m].x = array[i].x;
			arrayx[m].y = array[i].y;
			m++;
		}
		else
		{
			ok = 1;
			break;
		}
	}
	if (ok == 1) 
		return 0;
	else
	{
		int a1 = arrayx[0].x, b1 = arrayx[0].y;
		int a2 = arrayx[1].x, b2 = arrayx[1].y;
		int a3 = arrayx[2].x, b3 = arrayx[2].y;
		if (a1 == a2 && b1 == a3 && b2 == b3)
			return 1;
		if (a1 == b2 && b1 == a3 && a2 == b3)
			return 1;
		if (a1 == a2 && b1 == b3 && b2 == a3)
			return 1;
		if (a1 == b2 && b1 == b3 && a2 == a3)
			return 1;
		if (a1 == a3 && b1 == a2 && b2 == b3)
			return 1;
		if (a1 == a3 && b1 == b2 && a2 == b3)
			return 1;
		if (a1 == b3 && b1 == a2 && b2 == a3)
			return 1;
		if (a1 == b3 && b1 == b2 && a2 == a3)
			return 1;
	}
	return 0;
}
int main(){
	while (scanf("%d", &array[0].x) != EOF)
	{
		scanf("%d", &array[0].y);
		if (array[0].x > array[0].y)
		{
			int temp = array[0].x;
			array[0].x = array[0].y;
			array[0].y = temp;
		}
		for (int i = 1; i < 6; i++)
		{
			scanf("%d%d", &array[i].x, &array[i].y);
			if (array[i].x > array[i].y)
			{
				int temp = array[i].x;
				array[i].x = array[i].y;
				array[i].y = temp;
			}
		}
		sort(array, array + 6, cmp);
		int ok = solve();
		if (ok)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}