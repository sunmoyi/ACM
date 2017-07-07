#include<iostream>
#include<cstring>

using namespace std;

class MyString
{
public:
	MyString() {};
	MyString(char*str);
	MyString(MyString &s1);
	void add(MyString &s1, MyString &s2);
	int get_n() { return n; }
	char *get_str() { return str; }
	void show()
	{
		cout << str << endl;
	}
	~MyString()
	{
		delete[]str;
		cout << "Destructor Called." << endl;
	}
private:
	int n;
	char *str;
};

MyString::MyString(char *str)
{
	n = strlen(str);
	this->str = new char[n + 1];
	strcpy(this->str, str);
}

MyString::MyString(MyString &s1)
{
	n = s1.get_n();
	//str = new char[n + 1];
	str = s1.get_str();
}

void MyString::add(MyString &s1, MyString &s2)
{
	n = s1.get_n() + s1.get_n();
	str = new char[n + 1];
	if (str != 0)
		strcpy(str, s1.str);
	strcat(str, s2.str);
}

int main()
{
	MyString b1("I'll make it."), b2("Thank you!"), b3, b4(b3);
	cout << "Input a string:" << endl;
	b1.show();
	cout << "���ַ����ĳ���Ϊ��" << b1.get_n() << endl;
	cout << "Input a other string:" << endl;
	b2.show();
	cout << "���ַ����ĳ���Ϊ��" << b2.get_n() << endl;
	b3.add(b1, b2);
	cout << "��Ӻ���ַ���Ϊ��" << endl;
	b3.show();
	cout << "�ַ����ĳ���Ϊ��" << b3.get_n() << endl;
	cout << "�������ʵ�ֵ��ַ���Ϊ��" << endl;
	b4.show();
	cout << "�ַ����ĳ���Ϊ��" << b4.get_n() << endl;
	return 0;
}