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
	for (c = s[ith++]; ith<s.size() && c != ')'; c = s[ith++])//�ݹ�������������ַ������������������� 
	{
		for (k = 0; isdigit(c); c = s[ith++])
			k = k * 10 + c - '0';
		if (!k) 
			k = 1;
		if (c == '(')
		{
			while (k--)
				e = fun(ith);
			ith = e;//����ith��ֵ�����²�ݹ������λ�� 
		}
		else
		{
			while (k--)
				putchar(c);
		}
	}
	if (c == ')') 
		return ith;//���ر��ζ�����β��λ�� 
}
int main()
{
	int i, j, k, T;
	cin >> T;
	while (T--)
	{
		s.clear();
		cin >> s;
		fun(0);//����ݹ� 
		cout << endl;
	}
	return 0;
}