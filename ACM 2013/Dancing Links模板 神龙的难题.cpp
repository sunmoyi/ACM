/* ***********************************************
Author        :kuangbin
Created Time  :2014/5/27 17:53:47
File Name     :E:\2014ACM\专题学习\DLX\FZU1686.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MaxM = 15 * 15 + 10;
const int MaxN = 15 * 15 + 10;
const int maxnode = MaxN * MaxM;
const int INF = 0x3f3f3f3f;
struct DLX
{
	int n, m, size;// size初始化为列数 n行数  m列数
	int U[maxnode], D[maxnode], R[maxnode], L[maxnode], Row[maxnode], Col[maxnode];// Col 列标
	int H[MaxN], S[MaxM];
	int ansd;
	void init(int _n, int _m)
	{
		n = _n;
		m = _m;
		for (int i = 0; i <= m; i++)
		{
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[m] = 0; L[0] = m;
		size = m;
		for (int i = 1; i <= n; i++)H[i] = -1;
	}
	void Link(int r, int c)// r第几个进行Link操作 r所对应的 size = r + m  c是深搜起始点的ID编号
	{
		++S[Col[++size] = c];//S数组保存当前的过程中的答案 以供最后的输出使用
		Row[size] = r; // 当前元素所在的行 Row 在下面所有的此层搜索的代码中 size代表的是此次搜索
		D[size] = D[c]; //用size来纪录当前的C对应的上下左右的指向 为了等等的 resume
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if (H[r] < 0)
			H[r] = L[size] = R[size] = size;
		else
		{
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}
	void remove(int c)// 排除C所在的列   （重复覆盖）   PS： 精确覆盖  排除行
	{
		for (int i = D[c]; i != c; i = D[i])
			L[R[i]] = L[i], R[L[i]] = R[i];
	}
	void resume(int c)// 添加列C 
	{
		for (int i = U[c]; i != c; i = U[i])
			L[R[i]] = R[L[i]] = i;
	}
	bool v[MaxM];
	int f() //Hash 函数
	{
		int ret = 0;
		for (int c = R[0]; c != 0; c = R[c])v[c] = true;// 将剩下的数种的1进行标记
		for (int c = R[0]; c != 0; c = R[c])//子啊一次遍历所有的点
			if (v[c])
			{
				ret++;
				v[c] = false;
				for (int i = D[c]; i != c; i = D[i])
					for (int j = R[i]; j != i; j = R[j])
						v[Col[j]] = false;//
			}
		return ret;
	}
	void Dance(int d)
	{
		if (d + f() >= ansd)return; // ansd 表示重复覆盖的最小个数
		if (R[0] == 0)              
		{
			if (d < ansd)ansd = d;
			return;
		}
		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])
			if (S[i] < S[c])
				c = i;
		for (int i = D[c]; i != c; i = D[i])
		{
			remove(i);
			for (int j = R[i]; j != i; j = R[j])remove(j);
			Dance(d + 1);
			for (int j = L[i]; j != i; j = L[j])resume(j);
			resume(i);
		}
	}
};
DLX g;

int a[20][20];
int id[20][20];// id[i][j] i行j列的那个数的编号

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n, m;// n 行数 m列数
	while (scanf("%d%d", &n, &m) == 2)
	{
		int sz = 0;
		memset(id, 0, sizeof(id));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &a[i][j]);//读入行列
				if (a[i][j] == 1)id[i][j] = (++sz);// 读入编号
			}
		g.init(n*m, sz);
		sz = 1;
		int n1, m1;// n1  AOE伤害的长 m1 AOE 伤害的宽
		scanf("%d%d", &n1, &m1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				for (int x = 0; x < n1 && i + x < n; x++)
					for (int y = 0; y < m1 && j + y < m; y++)
						if (id[i + x][j + y])//如果以（i, j）为某一个坐标 进行AOE覆盖 
							//如果覆盖到的点中有含有标号的点    深搜
							g.Link(sz, id[i + x][j + y]);//Link参数 sz 深搜的次数 深搜的“1”的位置
				sz++;
			}
		g.ansd = INF;
		g.Dance(0);
		printf("%d\n", g.ansd);
	}
	return 0;
}