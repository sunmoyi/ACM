#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

char str[550];


int main (void)
{
	while (gets_s(str))
	{
		for (int i = 0; str[i] != 0; i++)
		{
			if (iswupper(str[i]))
				str[i] = towlower(str[i]);
		}
		printf("%s\n", str);
	}
}