#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

string s;

int fun(int ith)
{
	int k, e;
	char c;
	for (c = s[ith++]; ith<s.size() && c != ')'; c = s[ith++])//递归结束的条件是字符串结束或遇到右括号 
	{
		for (k = 0; isdigit(c); c = s[ith++])
			k = k * 10 + c - '0';
		if (!k) 
			k = 1;
		if (c == '(')
		{
			while (k--)
				e = fun(ith);
			ith = e;//重置ith的值，到下层递归结束的位置 
		}
		else
		{
			while (k--)
				putchar(c);
		}
	}
	if (c == ')') 
		return ith;//返回本次读到结尾的位置 
}
int main()
{
	int i, j, k, T;
	cin >> T;
	while (T--)
	{
		s.clear();
		cin >> s;
		fun(0);//进入递归 
		cout << endl;
	}
	return 0;
}