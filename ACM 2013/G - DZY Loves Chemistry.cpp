/*#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct react{
	int a;
	int b;
}a[125000];

struct num{
	int sum;
	int pos;
}k[55];

bool cmp(num a, num b)
{
	return a.sum > b.sum;
}

int main(void)
{
	int reat = 1;
	int cup[55], num_of_cup = 0;
	int n, m;

	while (scanf("%d %d", &n, &m) != EOF)//n����Ԫ�صĸ��� m������Է�Ӧ�ĸ���
	{
		reat = 1;
		num_of_cup = 0;
		memset(cup, 0, sizeof(cup));
		memset(k, 0, sizeof(k));
		memset(a, 0, sizeof(a));��pos��iһһ��Ӧ ���⽫����Ԫ�صķ�Ӧ��������
		{
		for (int i = 1; i < 55; i++)//
			k[i].pos = i;
			k[i].sum = 0;
		}
		
		for (int i = 0; i < m; i++)//��ȡ���Է�Ӧ��Ԫ�صĸ��� ��Ӧ�ĸ�����0��ʼ����
		{
			scanf("%d %d", &a[i].a, &a[i].b);
			k[a[i].a].sum++;
			k[a[i].b].sum++;
		}
		sort(k + 1, k + n + 1, cmp);
		for (int i = 1; i <= n; i++)//ÿ�η����Ԫ��
		{
			int flag = 0;
			for (int j = 1; j <= num_of_cup; j++)//�����е�ÿ��Ԫ�صı���
			{
				for (int ss = 0; ss < m; ss++)//����ÿ����ѧ���� ���Ƿ��з���������ѭ���ķ���
				{
					if (a[ss].a = k[i].pos && a[ss].b == cup[j] || a[ss].a == cup[j] && a[ss].b == k[i].pos) //i�Ƿ����Ԫ�� cup[j]�Ǳ����еĵ�J��Ԫ��
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1)
					break;
			}
			if (flag == 1)
				reat *= 2;
			cup[ ++num_of_cup ] = k[i].pos;
		}
		printf("%d\n", reat);
	}
}*/


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

struct way{
	int a;
	int b;
};
way ways[15000];
int vis[55];
int n, m;//n��ʾԪ�ص����� m��ʾ·��
void bfs(int b)
{
	queue<int>q;
	q.push(b);
	vis[b] = 1;
	while (!q.empty())
	{
		int element = q.front(), next;
		q.pop();
		for (int i = 0; i < m; i++)
		{
			if (ways[i].a == element && vis[ways[i].b] == 0)
			{
				next = ways[i].b;
				q.push(next);
				vis[ways[i].b] = 1;
			}
			if (ways[i].b == element && vis[ways[i].a] == 0)
			{
				next = ways[i].a;
				q.push(next);
				vis[ways[i].a] = 1;
			}
		}
	}
}

int main(void)
{
	
	while (scanf("%d %d", &n, &m) != EOF)
	{
		int count = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; i++)
			scanf("%d %d", &ways[i].a, &ways[i].b);
		for (int i = 1; i <= m; i++)
		{
			if (!vis[i])
			{
				count++;
				bfs(i);
			}
		}
		long long sun = 1;
		for (int i = 1; i <= n - count; i++)
		{
			sun *= 2;
		}
		printf("%lld\n", sun);
	}
	return 0;
}