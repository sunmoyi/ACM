#include<iostream>
#include<map>
#include<string>
using namespace std;

const int inf = 10000;     
int n;     
int m;     

map<string, int>STL;     

double rate;
char str[50], str1[50], str2[50];
double dist[31][31];

int i, j, k;

void floyd(void)
{
	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (dist[i][j] < dist[i][k] * dist[k][j])       
					dist[i][j] = dist[i][k] * dist[k][j];
	return;
}

int main(void)
{
	int cases = 1;
	while (cases)
	{
		

		memset(dist, inf, sizeof(dist));

		

		cin >> n;
		if (!n)break;

		for (i = 1; i <= n; i++)
		{
			cin >> str;
			STL[str] = i;         
			dist[i][i] = 1;        
								  
		}

		cin >> m;
		for (i = 1; i <= m; i++)
		{
			cin >> str1 >> rate >> str2;
			dist[STL[str1]][STL[str2]] = rate;     
		}
		

		floyd();

		int flag = false;
		for (i = 1; i <= n; i++)
			if (dist[i][i]>1)
			{
				flag = true;
				break;
			}
		if (flag)
			cout << "Case " << cases++ << ": Yes" << endl;
		else
			cout << "Case " << cases++ << ": No" << endl;
	}
	return 0;
}