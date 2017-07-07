/* ***********************************************
Author        :kuangbin
Created Time  :2014/5/27 17:53:47
File Name     :E:\2014ACM\ר��ѧϰ\DLX\FZU1686.cpp
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
	int n, m, size;// size��ʼ��Ϊ���� n����  m����
	int U[maxnode], D[maxnode], R[maxnode], L[maxnode], Row[maxnode], Col[maxnode];// Col �б�
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
	void Link(int r, int c)// r�ڼ�������Link���� r����Ӧ�� size = r + m  c��������ʼ���ID���
	{
		++S[Col[++size] = c];//S���鱣�浱ǰ�Ĺ����еĴ� �Թ��������ʹ��
		Row[size] = r; // ��ǰԪ�����ڵ��� Row ���������еĴ˲������Ĵ����� size������Ǵ˴�����
		D[size] = D[c]; //��size����¼��ǰ��C��Ӧ���������ҵ�ָ�� Ϊ�˵ȵȵ� resume
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
	void remove(int c)// �ų�C���ڵ���   ���ظ����ǣ�   PS�� ��ȷ����  �ų���
	{
		for (int i = D[c]; i != c; i = D[i])
			L[R[i]] = L[i], R[L[i]] = R[i];
	}
	void resume(int c)// �����C 
	{
		for (int i = U[c]; i != c; i = U[i])
			L[R[i]] = R[L[i]] = i;
	}
	bool v[MaxM];
	int f() //Hash ����
	{
		int ret = 0;
		for (int c = R[0]; c != 0; c = R[c])v[c] = true;// ��ʣ�µ����ֵ�1���б��
		for (int c = R[0]; c != 0; c = R[c])//�Ӱ�һ�α������еĵ�
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
		if (d + f() >= ansd)return; // ansd ��ʾ�ظ����ǵ���С����
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
int id[20][20];// id[i][j] i��j�е��Ǹ����ı��

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n, m;// n ���� m����
	while (scanf("%d%d", &n, &m) == 2)
	{
		int sz = 0;
		memset(id, 0, sizeof(id));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &a[i][j]);//��������
				if (a[i][j] == 1)id[i][j] = (++sz);// ������
			}
		g.init(n*m, sz);
		sz = 1;
		int n1, m1;// n1  AOE�˺��ĳ� m1 AOE �˺��Ŀ�
		scanf("%d%d", &n1, &m1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				for (int x = 0; x < n1 && i + x < n; x++)
					for (int y = 0; y < m1 && j + y < m; y++)
						if (id[i + x][j + y])//����ԣ�i, j��Ϊĳһ������ ����AOE���� 
							//������ǵ��ĵ����к��б�ŵĵ�    ����
							g.Link(sz, id[i + x][j + y]);//Link���� sz ���ѵĴ��� ���ѵġ�1����λ��
				sz++;
			}
		g.ansd = INF;
		g.Dance(0);
		printf("%d\n", g.ansd);
	}
	return 0;
}