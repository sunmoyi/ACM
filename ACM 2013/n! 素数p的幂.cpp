#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int main (void)
{
	int n, t, sum = 0, k;
	cin >> n >> k;
	int temp = k;
	while (temp <= n)
	{
		sum += n / temp;
		temp *= k;
	}
	cout << sum << endl;
	
	return 0;
}