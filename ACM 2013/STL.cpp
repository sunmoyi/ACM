#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>
#include<iostream>

using namespace std;
int main(void)
{
	deque<int> d{ 1,2,3,4,5 };
	deque<int>::reverse_iterator it;
	for (it = d.rbegin(); it != d.rend(); it++) 
	{
		cout << *it << " ";
	}
	cout << endl;
}