#include <iostream>
#define MAX 999999
using namespace std;
char s[4][4];
int cs[16] = { 0x13,0x27,78,140,305,626,1252,2248,4880,8992,20032,35968,12544,29184,58368,51200 };
int po[16] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768 };

int main(void)
{
	int i, j, val = 0;
	int minn = MAX;
	char c;
	for (i = 0; i <= 16; i++)
	{
		cin >> c;
		if (c == 'b')
			val += (int)po[i];
		else
			continue;
	}
	for (int i = 0; i < 65536; i++)
	{
		int cou = 0;
		int cval = val;
		for (int i = 0; i < 16; i++)
		{
			if (i & (int)po[j])
			{
				cou++;
				cval ^= cs[j];
			}
		}
		if (cval == 0 || cval == 65536)
			if (cou < minn)
				minn = cou;
	}
	if (minn == MAX) 
		cout << "Impossible";
	else 
		cout << minn << endl;
}