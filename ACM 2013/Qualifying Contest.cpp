#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
	char name[15];
	int sit;
	int score;
}date[100010];
int n, m;

bool cmp(node &a, node &b)
{
	if (a.sit == b.sit)
		return a.score > b.score;
	else
		return a.sit < b.sit;
}

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(date, 0, sizeof(date));
		for (int i = 1; i <= n; i++)
		{
			getchar();
			scanf("%s", date[i].name);
			scanf("%d %d", &date[i].sit, &date[i].score);
		}

		sort(date + 1, date + n + 1, cmp);

		for (int i = 1; i <= n;)
		{
			if (date[i].sit != date[i + 2].sit)
			{
				printf("%s %s\n", date[i].name, date[i + 1].name);
			}
			else
			{
				if (date[i + 1].score == date[i + 2].score)
					printf("?\n");
				else
				{
					printf("%s %s\n", date[i].name, date[i + 1].name);
				}
			}
			int ss = i;
			while (date[i].sit == date[ss].sit && i <= n)
				i++;
		}
	}
	return 0;
}