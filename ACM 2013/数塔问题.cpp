#include <iostream>
#define MAX 20
using namespace std;
int main()
{
	cout << "Please input N(lines)" << endl;
	int n;
	cin >> n;
	int a[MAX + 1][MAX + 1][3]; //[0]用来存数，[1]参与运算，[2]表示向左(0)，还是向右(1)
	//输入数塔
	for (int i = 1; i <= n; ++i)
	{
		cout << "Please input line " << i << endl;
		for (int j = 1; j <= i; ++j) //第i行有i个数
		{
			cin >> a[i][j][0];
			a[i][j][1] = a[i][j][0];
			a[i][j][2] = 0;
		}
	}
	cout << endl;
	//计算
	for (int i = n - 1; i >= 1; --i) //从倒数第二行开始
	{
		for (int j = 1; j <= i; j++)
		{
			if (a[i + 1][j][1] > a[i + 1][j + 1][1]) //左边大
			{
				a[i][j][2] = 0; //选择左边
				a[i][j][1] += a[i + 1][j][1];
			}
			else //右边大
			{
				a[i][j][2] = 1; //选择右边
				a[i][j][1] += a[i + 1][j + 1][1];
			}
		}
	}
	//输出数塔
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << a[i][j][0] << " ";
		}
		cout << endl;
	}
	//输出最大值
	cout << a[1][1][1] << endl;
	//输出路径
	for (int i = 1, j = 1; i <= n; ++i)
	{
		cout << "[" << i << "," << j << "]" << " -> ";
		j += a[i][j][2];
	}
	cout << endl;
	return 0;
}
