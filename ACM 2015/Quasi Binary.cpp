#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>G;
char str[10];
int maxx = 0;

int main(void)
{
	while (scanf("%s", str) != EOF)
	{
		G.clear();
		maxx = 0;
		for (int i = 0; str[i] != 0; i++)
			maxx = max(maxx, str[i] - '0');
		printf("%d\n", maxx);
		while (maxx--)
		{
			int temp = 0;
			for (int i = 0; str[i] != 0; i++)
			{
				temp *= 10;
				if (str[i] != '0')
				{
					temp += 1;
					str[i]--;
				}
			}
			G.push_back(temp);
		}
		for (int i = G.size() - 1; i >= 1; i--)
			printf("%d ", G[i]);
		printf("%d\n", G[0]);
	}
	return 0;
}