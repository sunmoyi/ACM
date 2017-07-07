#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

unsigned long long l, r, ans;

int main(void)
{
	cin >> l >> r;
	int i;
	for (i = 63; i >= 0; i--)
		if ((l & (1ll << i)) ^ (r & (1ll << i)))
			break;
	for (; i >= 0; i--)
		ans |= (1ll << i);
	cout << ans << endl;
	return 0 ;
}