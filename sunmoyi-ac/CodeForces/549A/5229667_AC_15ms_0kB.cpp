#include<cstdio>
#include<cstring>

using namespace std;

char str[55][55];

bool check (int x, int y)
{
	int k[5];
	memset(k , 0, sizeof(k));
	for(int i = 0; i <= 1; i++)
	{
		for(int j = 0; j <= 1; j++)
		{
			if(str[x + i][y + j] == 'f')
				k[1]++;
			if(str[x + i][y + j] == 'a')
				k[2]++;
			if(str[x + i][y + j] == 'c')
				k[3]++;
			if(str[x + i][y + j] == 'e')
				k[4]++;
		}
	}
	for(int i = 1; i <= 4; i++)
		if(k[i] == 0)
			return false;
	return true;
}
int main (void)
{
	int h, w;
	while(scanf("%d %d", &h, &w)!= EOF)
	{
		getchar();
		for(int i = 1; i <= h; i++)
		{
			for(int j = 1; j <= w; j++)
			{
				scanf("%c", &str[i][j]);
			}
			getchar();
		}
		int num = 0;
		for(int i = 1; i < h; i++)
		{
			for(int j = 1; j < w; j++)
			{
				if(check(i, j))
				{
					num++;
				}
			}
		}
		printf("%d\n", num);
	}
	return 0;
}