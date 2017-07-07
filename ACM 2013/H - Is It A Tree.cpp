/*
 *��������
 *��������
 *��������
 *��������
 *
 *
 *1. ���ո��ڵ�ֻ����һ��
 *2. ÿ���ڵ�����ֻ��Ϊһ
 *3. �ڽ�ͼ��ʱ��������������ո��ڵ㲻����ͬ
 *4. �ϲ���ʱ���ܻ��� ��������ͼ ���ӷ���һ��
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int Max = 100000 + 10;
int Far[Max];
int Rank[Max]; //��Ϊ��ǽ������
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
	//��Ϊ������ͼ���ϲ��������ֻ��һ��
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
	//��ʼ��
	int flag = 1;
	int k = 1;
	Make_set(Max);
	while (cin >> a >> b)
	{
		if (a < 0 || b < 0)
			return 0;
		if (a == 0 && b == 0) //��һ������������Ϻ��������
		{
			int ans = 0;
			for (int i = 1; i<Max; i++)
			{
				if (Sign[i] && Find_set(i) == i)  //ͳ���м�����ͨ��֧
					ans++;
				if (Rank[i] > 1)  //��������ȴ���һ�Ľ��Ͳ������ˣ���ͼ
				{
					flag = 0;
					break;
				}
			}
			if (ans > 1)  //��ͨ��֧����1����ʾ�Ƿ�Ϊɭ��
				flag = 0;
			if (flag)
				cout << "Case " << k++ << " is a tree." << endl;
			else
				cout << "Case " << k++ << " is not a tree." << endl;
			//���³�ʼ��
			flag = 1; //��ʾΪYes
			Make_set(Max);
			continue;
		}
		if (a != b && Find_set(a) == Find_set(b))  //���ڵ���ͬ����Ҷ�Ӳ�ͬ����ʾa��b�Ѵ���·�������
		{                                          //������һ��·�������ڻ������еڶ���·��
			//cout<<"No"<<endl;
			flag = 0;
		}
		else
		{
			Sign[a] = 1;
			Sign[b] = 1;
			Rank[b] ++;  //��ȼ�һ
			Unio(a, b);  //b���ϴ���a��ֻ����һ��������Ϊ������ͼ
		}
	}
	return 0;
}