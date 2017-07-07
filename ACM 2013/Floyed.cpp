#include<cstdio>
#include<math.h>
#include<cstring>
#include<algorithm>

using namespace std;

int d[1000][1000];
int V;

void Floyd(void)
{
	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}
	}
}