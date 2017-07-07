#include <iostream>
#include<map>
#include<string>
using namespace std;

const int inf = 10000;      //无限大
int n;      //货币种类
int m;      //兑换方式

map<string, int>STL;     //建立一个 使字符串与整数有一一对应关系 的容器STL,以便利用邻接矩阵存储数据

double rate;
char str[50], str1[50], str2[50];
double dist[31][31];

int i, j, k;

void floyd(void)
{
	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (dist[i][j] < dist[i][k] * dist[k][j])       //变形的最大路径，变"+"为"*"
					dist[i][j] = dist[i][k] * dist[k][j];
	return;
}

int main(void)
{
	int cases = 1;
	while (cases)
	{
		/*Initial*/

		memset(dist, inf, sizeof(dist));

		/*Input*/

		cin >> n;
		if (!n)break;

		for (i = 1; i <= n; i++)
		{
			cin >> str;
			STL[str] = i;          //将输入的货币从1到n依次编号
			dist[i][i] = 1;        //到自身的转换率默认为1，但通过floyd可能会被改变
								   //有向图的顶点（一般）存在环
		}

		cin >> m;
		for (i = 1; i <= m; i++)
		{
			cin >> str1 >> rate >> str2;
			dist[STL[str1]][STL[str2]] = rate;      //构造图
		}

		/*Floyd Algorithm*/

		floyd();

		/*Output*/

		int flag = false;
		for (i = 1; i <= n; i++)
			if (dist[i][i]>1)
			{
				flag = true;
				break;
			}
		if (flag)
			cout << "Case " << cases++ << ": Yes" << endl;
		else
			cout << "Case " << cases++ << ": No" << endl;
	}
	return 0;
}