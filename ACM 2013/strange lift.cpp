#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;

int N, A, B;
int a[205];
bool map[205], flag;

struct node
{
	int x, step;
}n1, n2, m;

int main()
{
	int i;
	while (scanf("%d", &N) && N)
	{
		scanf("%d %d", &A, &B);
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
			map[i] = false;
		}
		flag = false;
		n1.x = A; n1.step = 0;
		queue<node> Q;
		Q.push(n1);
		map[n1.x] = true;
		while (!Q.empty())
		{
			m = Q.front();
			Q.pop();
			if (m.x == B)    //到达目标
			{
				flag = true;
				break;
			}
			n1.x = m.x - a[m.x];
			n2.x = m.x + a[m.x];
			if (n1.x>0 && n1.x <= B && !map[n1.x]) //下去的
			{
				n1.step = m.step + 1;
				map[n1.x] = true;   //标记
				Q.push(n1);
			}
			if (n2.x>0 && n2.x <= B && !map[n2.x]) //上去的
			{
				n2.step = m.step + 1;
				map[n2.x] = true;   //标记
				Q.push(n2);
			}
		}
		if (flag) printf("%d\n", m.step);
		else printf("-1\n");
	}

	return 0;
}
