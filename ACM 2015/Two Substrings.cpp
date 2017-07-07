#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100010

using namespace std;

char str[maxn];
vector<int>GA, GB;

int main (void)
{
	scanf("%s", str);
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] == 'A' && str[i + 1] == 'B')
		{
			GA.push_back(i);
		}
		if (str[i] == 'B' && str[i + 1] == 'A')
		{
			GB.push_back(i);
		}
	}
	if (!GA.empty() && !GB.empty())
	{
		if (abs(GA[0] - GB[GB.size() - 1]) > 1 || abs(GA[GA.size() - 1] - GB[0]) > 1)
		{
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	else
		printf("NO\n");
	return 0;
} 