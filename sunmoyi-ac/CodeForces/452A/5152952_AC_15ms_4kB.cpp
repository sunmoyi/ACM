#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int num;
	char goal[8][10] = { "vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon" };
	char str[10];
	while (scanf("%d", &num) != EOF)
	{
		getchar();
		scanf("%s", str);
		for (int i = 0; i <= 7; i++)
		{
			if (strlen(goal[i]) == num)
			{
				bool flag = true;
				for (int j = 0; j < num; j++)
					if (str[j] != '.' && str[j] != goal[i][j])
						flag = false;
				if (flag)
				{
					printf("%s\n", goal[i]);
					break;
				}
			}
		}	
	}
	return 0;
}