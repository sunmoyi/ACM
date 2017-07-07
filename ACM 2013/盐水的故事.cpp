#include <iostream>  
#include <cmath>  
using namespace std;

int main()
{
	double v, d, n;
	int i, t;
	while (cin >> v >> d)
	{
		t = 0;
		i = 1;
		n = v / d;
		while (1)
		{
			if (n>i)
			{
				n -= i;
				t += (++i);
			}
			else
			{
				t += ceil(n);
				break;
			}
		}
		cout << t << endl;
	}
	return 0;
}