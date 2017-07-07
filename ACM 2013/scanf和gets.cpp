#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[20], s1[20];
	gets(s);
	gets(s1);
	printf("%s", s1);

	//第一句的回车不会被第二句读入  因为gets读入回车但是扔掉    
	char q[10], p[10];
	scanf("%s",q);
	scanf("%s",p);
	printf("%s %s",q, p );
	//第一句的回车不会被第二句读入
	//简单说同型号的输入符不会互相传递回车符
}
