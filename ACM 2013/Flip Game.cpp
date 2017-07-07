#include <iostream>
#define MAX 999999
using namespace std;
char s[4][4];
int cs[16] = { 0x13,0x27,78,140,305,626,1252,2248,4880,8992,20032,35968,12544,29184,58368,51200 };
int po[16] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768 };
int main()
{
	int i, j, value = 0;
	int cmin = MAX;
	char c;
	for (i = 0; i < 16; i++)
	{
		cin >> c;
		if (c == 'b')
			value += (int)po[i];
		else  
			continue;
	}

	for (i = 0; i < 65536; i++)
	{
		int cou = 0;
		int cvalue = value;
		for (j = 0; j < 16; j++)
			if (i & (int)po[j])
			{
				cou++;
				cvalue ^= cs[j];
			}
		if (cvalue == 0 || cvalue == 65535)
			if (cou < cmin)  cmin = cou;
	}
	if (cmin == MAX) cout << "Impossible";
	else cout << cmin << endl;
	return 0;
}
//