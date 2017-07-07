#include<cstdio>  
#include<cstring>  
#include<string>  
#include<cmath>  
#include<queue>  
#include<stack>  
#include<map>  
const int MAX_COLOUMN = 16 * 16 * 16;//����������  
const int MAX_ROW = 16 * 16 * 16 + 2;//�����ֵ�����  

int cnt[MAX_COLOUMN];//cnt[i]ͳ�Ƶ�i��1�ĸ���  
int most, coloumn;
bool ans[MAX_ROW];//ans�������ѡ�е���  
//�������еĽڵ�  
struct Point
{
	int up, down, left, right;//�ϣ��£�����  
	int coloumn;//�õ����ڵ��б�  
	int row;//�б�  
}node[MAX_ROW*MAX_COLOUMN + MAX_COLOUMN];

//��ʼ����������ϢΪ��  
void init(int m)
{
	int i;
	for (i = 0; i <= m; i++)
	{
		node[i].down = i;
		node[i].up = i;
		node[i].coloumn = i;
		node[i].left = i - 1;
		node[i].right = i + 1;
		cnt[i] = 0;
	}
	node[0].left = m;
	node[m].right = 0;
}

void remove(int c)//ɾ��c��������1Ԫ�����ڵ���  
{
	node[node[c].right].left = node[c].left;
	node[node[c].left].right = node[c].right;
	int t, tt;
	for (t = node[c].down; t != c; t = node[t].down)//���ϵ��´�����ɾ�������ϵ�ÿһ����Ԫ����������Ϣ  
	{
		for (tt = node[t].right; tt != t; tt = node[tt].right)//ɾ������Ԫ��������  
		{
			cnt[node[tt].coloumn]--;
			node[node[tt].down].up = node[tt].up;
			node[node[tt].up].down = node[tt].down;
		}
	}
}

void resume(int c)//��ԭc��������1Ԫ�����ڵ���  
{
	int t, tt;
	for (t = node[c].up; t != c; t = node[t].up)//�������ϴ����һ�ԭ��c����1���ڵ�����Ϣ  
	{
		for (tt = node[t].left; tt != t; tt = node[tt].left)
		{
			cnt[node[tt].coloumn]++;
			node[node[tt].up].down = tt;
			node[node[tt].down].up = tt;
		}
	}

	node[node[c].right].left = c;
	node[node[c].left].right = c;
}

bool dfs(int k)//kΪ�Ѿ�ѡ�е��е���Ŀ  
{
	int i, j;
	if (k >= most)return false;
	if (node[coloumn].right == coloumn)//��ǰ��������Ϊ��  
	{
		if (k<most)
			most = k;
		return true;
	}

	int t = coloumn + 1;
	int c;
	//ѡȡ��ǰ������1���ٵ���  
	for (i = node[coloumn].right; i != coloumn; i = node[i].right)
	{
		if (cnt[i]<t)
		{
			c = i; t = cnt[i];
			if (t == 1)break;
		}
	}

	remove(c);//ɾ����c������1���ڵ���  

	//ɾ��ʱ�����Ҵ��ϵ��£���ԭʱ���µ��ϣ����ҵ���  
	for (i = node[c].down; i != c; i = node[i].down)
	{
		for (j = node[i].right; j != i; j = node[j].right)
		{
			remove(node[j].coloumn);
		}
		ans[node[j].row] = true;
		if (dfs(k + 1))
		{
			return true;
		}
		ans[node[j].row] = false;
		for (j = node[j].left; j != i; j = node[j].left)
		{
			resume(node[j].coloumn);
		}


	}

	resume(c);
	return false;
}
bool graph[MAX_ROW][MAX_COLOUMN];
void addrow(int i, int j, int k)
{
	int curr = (i * 16 + j) * 16 + k;
	graph[curr][(i * 16 + j)] = true;
	graph[curr][16 * 16 + i * 16 + k] = true;
	graph[curr][16 * 16 * 2 + j * 16 + k] = true;
	int tr = i / 4;
	int tc = j / 4;
	graph[curr][16 * 16 * 3 + (tr * 4 + tc) * 16 + k] = true;
}

char str[MAX_ROW];
int main()
{
	int N, M, i, j, k, nu;
	while (scanf_s("%s", str, MAX_ROW - 1) != EOF)
	{
		nu = 1;
		while (scanf_s("%s", str + nu * 16)){ nu++; if (nu == 16)break; }
		N = 16 * 16 * 16;
		M = 16 * 16 * 4;
		coloumn = M;
		int cur = coloumn + 1;//��ǰ�ڵ���  
		init(coloumn);
		memset(graph, 0, sizeof(graph));
		for (i = 0; i<16; i++)
			for (j = 0; j<16; j++)
			{
				if (str[i * 16 + j] == '-')
				{
					for (k = 0; k<16; k++)//����ÿһ����ɫ  
					{
						addrow(i, j, k);
					}
					continue;
				}
				k = str[i * 16 + j] - 'A';
				addrow(i, j, k);
			}
		for (i = 0; i<N; i++)
		{
			int start = cur;//��¼��i�еĿ�ʼ����  
			int pre = cur;//��¼�����е�ǰ1����ߵ�һ��1���  
			for (j = 0; j<M; j++)
			{
				// scanf("%d",&n);  
				if (graph[i][j])//�������н������0Ԫ��  
				{
					int pos = j;
					node[cur].up = node[pos].up;
					node[node[pos].up].down = cur;
					node[cur].down = pos;
					node[pos].up = cur;
					cnt[pos]++;//����1�ĸ���+1  
					node[cur].coloumn = pos;
					node[cur].left = pre;
					node[pre].right = cur;
					node[cur].right = start;
					node[start].left = cur;
					node[cur].row = i;
					pre = cur++;
				}
			}
		}


		most = N + 1;//��¼������Ҫѡ�е�����  
		memset(ans, false, sizeof(ans));
		dfs(0);
		// printf("Yes, I found it\n");  
		for (int k = 0; k<16; k++)
		{
			for (i = 0; i<16; i++)
			{
				for (j = 0; j<16; j++)
				{
					if (ans[(k * 16 + i) * 16 + j])
						putchar(j + 'A');
				}
			}
			printf("\n");
		}
	}
	return 0;
}

/*
��������
--A----C-----O-I
-J--A-B-P-CGF-H-
--D--F-I-E----P-
-G-EL-H----M-J--
----E----C--G---
-I--K-GA-B---E-J
D-GP--J-F----A--
-E---C-B--DP--O-
E--F-M--D--L-K-A
-C--------O-I-L-
H-P-C--F-A--B---
---G-OD---J----H
K---J----H-A-P-L
--B--P--E--K--A-
-H--B--K--FI-C--
--F---C--D--H-N-

*/