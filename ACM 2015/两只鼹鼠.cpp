#include <iostream>  
#include <cstring>  
using namespace std;
int n;
int la, lb;
int ia, ib;
int fa, fb;
int a[10000];

int judge()
{
	int lq, xq;
	if (n % 2 == 0)
	{

		lq = (lb - la + n) % n;
		if (lq % 2 != 0)
			return -1;
		lq = lq / 2;
		xq = n / 2;
	}
	else
	{
		lq = (lb - la + n) % n;
		if (lq % 2 == 0)
			lq = lq / 2;
		else lq = (lq + n) / 2;
		xq = n;

	}
	//  cout<<lq<<" "<<xq<<endl;  
	int sum = 0;
	while (1)
	{
		int t1 = (lq - fa) % ia;
		int t2 = (lq - fb) % ib;
		//    cout<<lq<<"--"<<t1<<" "<<t2<<endl;  
		if (t1 == t2&&t1 == 0)
			return lq;
		lq += xq;
		// cout<<a[t1]<<endl;  
		if (a[t1] == t2)
			return -1;
		a[t1] = t2;
		sum++;
		if (sum>900000)
			return -1;
	}
}
int main()
{

	cin >> n;
	cin >> la >> lb;
	cin >> ia >> ib;
	cin >> fa >> fb;
	for (int i = 0; i<n; i++)
		a[i] = -1;
	int s = judge();

	if (s >= 0)
		cout << s << endl;
	else
		cout << "no answer" << endl;
	return 0;
}