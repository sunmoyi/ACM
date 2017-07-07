#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(int i, int k)
{
	int test, c;
	int t = 0;
	cin >> test;
	while (++t <= test)
	{
		cin >> c;
		char s1[201];   
		char s2[201];   
		char s12[401]; 
		cin >> s1 >> s2 >> s12;

		map<string, bool>vist;   
		vist[s12] = true;

		int step = 0;  
		while (true)
		{
			char s[201]; 
			int ps = 0; 
			for (i = 0; i<c; i++)    
			{
				s[ps++] = s2[i];
				s[ps++] = s1[i];
			}
			s[ps] = '\0';

			step++;

			if (!strcmp(s, s12))   
			{
				cout << t << ' ' << step << endl;
				break;
			}
			else if (vist[s] && strcmp(s, s12))  
			{                                  
				cout << t << ' ' << -1 << endl;
				break;
			}

			vist[s] = true;   

			for (i = 0; i<c; i++)   
				s1[i] = s[i];
			s1[i] = '\0';

			for (k = 0; i<2 * c; i++, k++)
				s2[k] = s[i];
			s2[i] = '\0';
		}
	}
	return 0;
}