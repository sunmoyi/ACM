#include<iostream>
using namespace std;
int main()
{
	int t;
	double y, q, e, f, g, sum;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> y >> q >> e >> f >> g;
			sum = y*(1 + (e / 100)*(q / 365));
			sum = sum*(1 + g / 100);
			cout << sum << endl;
			sum = y*(1 + (f / 100)*(q + 365) / 365);
			cout << sum << endl;
		}
	}
	return 0;
}
