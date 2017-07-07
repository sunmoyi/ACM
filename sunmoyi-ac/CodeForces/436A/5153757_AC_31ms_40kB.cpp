#include <cstdio>
#include <cstring>
#include<algorithm>

using namespace std;

int k[2005][4];

int main()
{
	int n, x;
	while (scanf("%d%d", &n, &x) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &k[i][1], &k[i][2], &k[i][3]);
		}
		int ans = 0;
		for (int i = 0; i < 2; i++)  
		{
			for (int ss = 1; ss < 2005; ss++)
			{
				k[ss][0] = 0;
			}
			int curx = x;
			int curtype = i;
			int curid = 0;
			int curans = 0;
			while (true)
			{
				int curm = 0;
				for (int j = 1; j <= n; j++)
				{
					if (!k[j][0] && k[j][1] == curtype && curx >= k[j][2] && curm <= k[j][3])
					{
						curm = k[j][3];   
						curid = j;
					}
				}
				if (curm == 0)  
					break;
				k[curid][0] = 1;  
				curans++;        
				curx += curm;     
				curtype ^= 1;    
			}
			ans = max(ans, curans);
		}
		printf("%d\n", ans);
	}
	return 0;
}