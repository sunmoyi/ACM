#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

class Box {
public:
	Box();
	Box(double a)
	{
		side = a;
	}
	double set_mianji() { return mianji = 6 * side * side; }
	double set_tiji() { return tiji = pow(side, 3); }
	void get_num() {
		cout << "�����" << set_mianji() << endl;
		cout << "�����" << set_tiji() << endl;
	}
private:
	double side, mianji, tiji;
};

int main(void)
{
	double side;
	cin >> side;
	Box box(side);
	box.get_num();
	return 0;
}