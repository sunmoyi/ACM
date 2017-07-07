#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class A {
public:
	virtual void print(void) { printf("1\n"); }
};

class B :public A {
public:
	virtual void print(void) { printf("2\n"); }
};

class C :public A {
public:
	virtual void print(void) { printf("3\n"); }
};

void fun(A & a)
{
	a.print();
}

int main(void)
{
	A a;
	B b;
	C c;
	fun(a);
	fun(b);
	fun(c);

	return 0;
}