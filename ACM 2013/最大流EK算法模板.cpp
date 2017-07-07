#include <iostream>
#include <queue>
#include<string.h>
using namespace std;
#define arraysize 201
int maxData = 0x7fffffff;
int capacity[arraysize][arraysize]; //��¼�������������
int flow[arraysize];                //��Ǵ�Դ�㵽��ǰ�ڵ�ʵ�ʻ�ʣ������������
int pre[arraysize];                 //���������·���ϵ�ǰ�ڵ��ǰ��,ͬʱ��Ǹýڵ��Ƿ��ڶ�����
int n, m;
queue<int> myqueue;
int BFS(int src, int des)
{
	int i, j;
	while (!myqueue.empty())       //�������
		myqueue.pop();
	for (i = 1; i<m + 1; ++i)
	{
		pre[i] = -1;
	}
	pre[src] = 0;
	flow[src] = maxData;
	myqueue.push(src);
	while (!myqueue.empty())
	{
		int index = myqueue.front();
		myqueue.pop();
		if (index == des)            //�ҵ�������·��
			break;
		for (i = 1; i<m + 1; ++i)
		{
			if (i != src && capacity[index][i]>0 && pre[i] == -1)
			{
				pre[i] = index; //��¼ǰ��
				flow[i] = min(capacity[index][i], flow[index]);   //�ؼ����������ҵ�����
				myqueue.push(i);
			}
		}
	}
	if (pre[des] == -1)      //����ͼ�в��ٴ�������·��
		return -1;
	else
		return flow[des];
}
int maxFlow(int src, int des)
{
	int increasement = 0;
	int sumflow = 0;
	while ((increasement = BFS(src, des)) != -1)
	{
		int k = des;          //����ǰ��Ѱ��·��
		while (k != src)
		{
			int last = pre[k];
			capacity[last][k] -= increasement; //�ı�����ߵ�����
			capacity[k][last] += increasement; //�ı䷴��ߵ�����
			k = last;
		}
		sumflow += increasement;
	}
	return sumflow;
}
int main()
{
	int i, j;
	int start, end, ci;
	while (cin >> n >> m)
	{
		memset(capacity, 0, sizeof(capacity));
		memset(flow, 0, sizeof(flow));
		for (i = 0; i<n; ++i)
		{
			cin >> start >> end >> ci;
			if (start == end)               //��������յ���ͬ�����
				continue;
			capacity[start][end] += ci;     //�˴�ע����ܳ��ֶ���ͬһ����յ�����
		}
		cout << maxFlow(1, m) << endl;
	}
	return 0;
}