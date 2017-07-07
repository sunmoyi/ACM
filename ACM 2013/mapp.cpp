#include<iostream>
#include<string>
#include<cctype>
#include<map>
using namespace std;
int main()
{
	string s;
	map<string, int> m;
	while (getline(cin, s) && s != "#")
	{
		string str;
		m.clear();
		int len = s.length();
		for (int i = 0; i<len; i++)
		{
			if (isalpha(s[i]))
			{
				str.clear();
				int j;
				for (j = i; isalpha(s[j]) && j<len; j++)
					str += s[j];
				i = j;
				m[str];
				m[str]++;
			}
		}
		cout << m.size() << endl;
	}
	return 0;
}