#include <iostream>
#include<map>
#include<string>
using namespace std;

const int inf = 10000;      //���޴�
int n;      //��������
int m;      //�һ���ʽ

map<string, int>STL;     //����һ�� ʹ�ַ�����������һһ��Ӧ��ϵ ������STL,�Ա������ڽӾ���洢����

double rate;
char str[50], str1[50], str2[50];
double dist[31][31];

int i, j, k;

void floyd(void)
{
	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (dist[i][j] < dist[i][k] * dist[k][j])       //���ε����·������"+"Ϊ"*"
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
			STL[str] = i;          //������Ļ��Ҵ�1��n���α��
			dist[i][i] = 1;        //�������ת����Ĭ��Ϊ1����ͨ��floyd���ܻᱻ�ı�
								   //����ͼ�Ķ��㣨һ�㣩���ڻ�
		}

		cin >> m;
		for (i = 1; i <= m; i++)
		{
			cin >> str1 >> rate >> str2;
			dist[STL[str1]][STL[str2]] = rate;      //����ͼ
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