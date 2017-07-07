#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(int agrc, char *agrv)
{
	int x, y;
	cout << "  欢迎使用本程序， 本程序能求得两个整数的和： " << endl;
	cout << "请输入两个整数：" << endl;
	cin >> x >> y;
	cout << "两个整数的和为：" << x + y << endl;
	return 0;
}