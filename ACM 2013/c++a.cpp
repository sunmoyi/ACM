#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string.h>

using namespace std;

class mystring {
public:
	mystring() {}
	mystring(char *strr)
	{
		str = new(char[strlen(strr) * 2]);
		if (str == NULL)
			printf("fail\n");
		strcpy(str, strr);
	}
	void set(char *strr)
	{
		str = new(char[strlen(strr) * 2]);
		if (str == NULL)
			printf("fail\n");
		strcpy(str, strr);
	}
	void dis() { printf("%s\n", str); }
	void friend operator + ( mystring a, mystring b)
	{
		strcat(a.str, b.str);
	}
private:
	char *str;
};

int main(void)
{
	mystring s1, s2;
	s1.set("aaaaaaaaaaaaaa");
	s2.set("bbbbbb");
	s1.dis();
	s2.dis();
	s1 + s2;
	s1.dis();
}