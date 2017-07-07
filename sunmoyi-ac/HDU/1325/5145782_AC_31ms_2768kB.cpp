/*
 *这题有向
 *这题有向
 *这题有向
 *这题有向
 *
 *
 *1. 最终父节点只能有一个
 *2. 每个节点的入度只能为一
 *3. 在建图的时候相连两点的最终父节点不能相同
 *4. 合并的时候不能化简 这是有向图 连接方向一定
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int Max = 100000 + 10;
int Far[Max];
int Rank[Max]; //改为标记结点的入度
int Sign[Max];

void Make_set(int n)
{
	int i;
	for (i = 0; i<n; i++)
	{
		Far[i] = i;
	}
	memset(Rank, 0, sizeof(Rank));
	memset(Sign, 0, sizeof(Sign));
}

int Find_set(int x)
{
	if (Far[x] != x)
		return Far[x] = Find_set(Far[x]);
	return Far[x];
}

void Unio(int a, int b)
{
	a = Find_set(a);
	b = Find_set(b);
	if (a == b)
		return;
	//因为是有向图，合并方向必须只有一个
	Far[b] = a;
	/*
	if(Rank[a] < Rank[b])
	Far[a] = b;
	else if(Rank[a] > Rank[b])
	Far[b] = a;
	else
	{
	Far[a] = b;
	Rank[b]++;
	}*/
}

int main()
{
	int a, b;
	//初始化
	int flag = 1;
	int k = 1;
	Make_set(Max);
	while (cin >> a >> b)
	{
		if (a < 0 || b < 0)
			return 0;
		if (a == 0 && b == 0) //待一组数据输入完毕后才输出结果
		{
			int ans = 0;
			for (int i = 1; i<Max; i++)
			{
				if (Sign[i] && Find_set(i) == i)  //统计有几个连通分支
					ans++;
				if (Rank[i] > 1)  //存在有入度大于一的结点就不是树了，是图
				{
					flag = 0;
					break;
				}
			}
			if (ans > 1)  //连通分支大于1，表示是否为森林
				flag = 0;
			if (flag)
				cout << "Case " << k++ << " is a tree." << endl;
			else
				cout << "Case " << k++ << " is not a tree." << endl;
			//从新初始化
			flag = 1; //表示为Yes
			Make_set(Max);
			continue;
		}
		if (a != b && Find_set(a) == Find_set(b))  //根节点相同，但叶子不同，表示a，b已存在路径，如果
		{                                          //仍增加一条路径则会存在环，则有第二天路径
			//cout<<"No"<<endl;
			flag = 0;
		}
		else
		{
			Sign[a] = 1;
			Sign[b] = 1;
			Rank[b] ++;  //入度加一
			Unio(a, b);  //b的老大是a，只能是一个方向，因为是有向图
		}
	}
	return 0;
}