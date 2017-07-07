#include<stack>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	stack<int>s;
	for (int i = 0; i <= 5; i++)
		s.push(i);
	while (!s.empty())
	{
		int a = s.top();
		s.pop();
		printf("%d	", a);
	}
	printf("\n");
	return 0;
}