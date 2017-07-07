#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
	int boss;
	int task;
	int num_of_task;
}s[500005];

void init(int x)
{
	for (int i = 1; i <= x; i++)
	{
		s[i].boss = i;
		s[i].task = -1;
		s[i].num_of_task = -1;
	}
}

int cheak(int x)
{
	int task = s[x].task;
	int task_of_number = s[x].num_of_task;
	int boss;
	while (s[x].boss != x)
	{
		boss = s[x].boss;
		if (s[boss].num_of_task > task_of_number)
		{
			task_of_number = s[boss].num_of_task;
			task = s[boss].task;
		}
		x = boss;
	}
	return task;
}

int main(void)
{
	int ans;
	while (scanf("%d", &ans) != EOF)
	{
		for (int i = 1; i <= ans; i++)
		{
			printf("Case #%d:\n", i);
			int n, m, a, b;
			scanf("%d", &n);
			init(n);
			for (int j = 1; j < n; j++)
			{
				scanf("%d %d", &a, &b);
				s[a].boss = b;
			}
			scanf("%d", &m);
			int kk = 1;
			for (int j = 1; j <= m; j++)
			{
				char ss;
				int q, p;
				do{ 
					scanf("%c", &ss);
				}while(!(ss == 'T' || ss == 'C'));
				if (ss == 'C')
				{
					scanf("%d", &q);
					printf("%d\n", cheak(q));
				}
				else
				{
					scanf("%d %d", &q, &p);
					s[q].task = p;
					s[q].num_of_task = kk++;
				}
			}
		}
	}
	return 0;
}