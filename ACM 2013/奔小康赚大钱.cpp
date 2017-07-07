#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 310;
const int INF = 0x3f3f3f3f;

int n, nx, ny;
int linker[N], lx[N], ly[N], slack[N];  //lx,lyΪ���꣬nx,ny�ֱ�Ϊx�㼯y�㼯�ĸ���
int visx[N], visy[N], w[N][N];

int DFS(int x)
{
	visx[x] = 1;
	for (int y = 1; y <= ny; y++)
	{
		if (visy[y])
			continue;
		int tmp = lx[x] + ly[y] - w[x][y];
		if (tmp == 0)
		{
			visy[y] = 1;
			if (linker[y] == -1 || DFS(linker[y]))
			{
				linker[y] = x;
				return 1;
			}
		}
		else if (slack[y] > tmp)
		{ //���������ͼ��slack ȡ��С��
			slack[y] = tmp;
		}
	}
	return 0;
}

int KM(){
	int i, j;
	memset(linker, -1, sizeof(linker));
	memset(ly, 0, sizeof(ly));
	for (i = 1; i <= nx; i++)      //lx��ʼ��Ϊ����������������
		for (j = 1, lx[i] = -INF; j <= ny; j++)
			if (w[i][j] > lx[i])
				lx[i] = w[i][j];
	for (int x = 1; x <= nx; x++)
	{
		for (i = 1; i <= ny; i++)
			slack[i] = INF;
		while (1)
		{
			memset(visx, 0, sizeof(visx));
			memset(visy, 0, sizeof(visy));
			if (DFS(x))  //���ɹ����ҵ�������죩����õ�������ɣ�������һ���������
				break;  //��ʧ�ܣ�û���ҵ�����죩������Ҫ�ı�һЩ��ı�ţ�ʹ��ͼ�п��бߵ��������ӡ�
			//����Ϊ����������������У���������������б���������X����ı��ȫ����ȥһ������d��
			//������������е�Y����ı��ȫ������һ������d
			int d = INF;
			for (i = 1; i <= ny; i++)
				if (!visy[i] && d > slack[i])
					d = slack[i];
			for (i = 1; i <= nx; i++)
				if (visx[i])
					lx[i] -= d;
			for (i = 1; i <= ny; i++)  //�޸Ķ����Ҫ�����в��ڽ������е�Y�����slackֵ����ȥd
				if (visy[i])
					ly[i] += d;
				else
					slack[i] -= d;
		}
	}
	int res = 0;
	for (i = 1; i <= ny; i++)
		if (linker[i] != -1)
			res += w[linker[i]][i];
	return res;
}

int main()
{

	//freopen("input.txt","r",stdin);

	while (~scanf("%d", &n))
	{
		nx = ny = n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &w[i][j]);
		int ans = KM();
		printf("%d\n", ans);
	}
	return 0;
}