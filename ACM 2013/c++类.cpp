#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>

using namespace std;

class MyLove
{
public:
	MyLove() {}
	MyLove(char *HisName, char *Hisheight) //构造函数
	{
		name = new char[strlen(HisName) + 100];
		strcpy(name, HisName);
		height = new char[strlen(Hisheight) + 100];
		strcpy(height, Hisheight);
	}
	void Get_name() { cout << name << " "; }
	void Get_height() { cout << height << " "; }
	void change(MyLove &a) { strcpy(name, a.name); strcpy(height, a.height); };
	MyLove(MyLove&c)  
	{
		if (!c.name)
			name = c.name;
		if (!c.height)
			height = c.height;
	}
	~MyLove()   
	{
		delete [] name;
		delete [] height;
	}
private:
	char *name = "abc";
	char *height = "100";

};


int main()
{
	MyLove idol1("Bosco", "180");
	MyLove idol2("ph", "181");
	MyLove mum("Ying", "170");
	MyLove brother("Heng", "172");
	cout << "before copy:" << endl;
	idol1.Get_name();
	idol1.Get_height();
	cout << endl;
	mum.Get_name();
	mum.Get_height();
	cout << endl;
	brother.Get_name();
	brother.Get_height();
	cout << endl;
	cout << "-----------我是分割线-----------" << endl;
	cout << "after copy:" << endl;
	idol2.change(mum);
	idol2.Get_name();
	idol2.Get_height();
	cout << endl;

	return 0;
}