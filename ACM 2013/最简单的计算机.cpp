#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main()
{
	LL m1, m2;
	char s[205];
	while (cin >> m1 >> m2)
	{
		scanf("%s", s);
		int l = strlen(s);
		int i;
		LL R1, R2, R3;
		R1 = R2 = R3 = 0;
		for (i = 0; i<l; i++)
		{
			if (s[i] == 'A')
				R1 = m1;
			if (s[i] == 'B')
				R2 = m2;
			if (s[i] == 'C')
				m1 = R3;
			if (s[i] == 'D')
				m2 = R3;
			if (s[i] == 'E')
				R3 = R1 + R2;
			if (s[i] == 'F')
				R3 = R1 - R2;
		}
		cout << m1 << "," << m2 << endl;
	}
	return 0;
}