#include <iostream>
#define MAX 20
using namespace std;
int main()
{
	cout << "Please input N(lines)" << endl;
	int n;
	cin >> n;
	int a[MAX + 1][MAX + 1][3]; //[0]����������[1]�������㣬[2]��ʾ����(0)����������(1)
	//��������
	for (int i = 1; i <= n; ++i)
	{
		cout << "Please input line " << i << endl;
		for (int j = 1; j <= i; ++j) //��i����i����
		{
			cin >> a[i][j][0];
			a[i][j][1] = a[i][j][0];
			a[i][j][2] = 0;
		}
	}
	cout << endl;
	//����
	for (int i = n - 1; i >= 1; --i) //�ӵ����ڶ��п�ʼ
	{
		for (int j = 1; j <= i; j++)
		{
			if (a[i + 1][j][1] > a[i + 1][j + 1][1]) //��ߴ�
			{
				a[i][j][2] = 0; //ѡ�����
				a[i][j][1] += a[i + 1][j][1];
			}
			else //�ұߴ�
			{
				a[i][j][2] = 1; //ѡ���ұ�
				a[i][j][1] += a[i + 1][j + 1][1];
			}
		}
	}
	//�������
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << a[i][j][0] << " ";
		}
		cout << endl;
	}
	//������ֵ
	cout << a[1][1][1] << endl;
	//���·��
	for (int i = 1, j = 1; i <= n; ++i)
	{
		cout << "[" << i << "," << j << "]" << " -> ";
		j += a[i][j][2];
	}
	cout << endl;
	return 0;
}
