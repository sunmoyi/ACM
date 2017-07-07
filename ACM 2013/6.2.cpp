#include<cstdio>
#include<cstring>
#define PI 3.1415926535

using namespace std;

class circle {
public:
	circle() {};
	circle(double RR = 0)
	{
		R = RR;
		S = PI * R * R;
	}
	void show(void)
	{
		printf("面积： %lf\n", S);
	}
private:
	double R;
	double S;
};

class table {
public:
	table() {};
	table(char *colorr, double highh = 0)
	{
		strcpy_s(color, colorr);
		high = highh;
	}
	void show(void)
	{
		printf("颜色： %s\n高度 ： %lf\n", color, high);
	}
private:
	char color[100];
	double high;
};

class roundtable :public circle, public table {
public:
	roundtable(char *colorr, double high, double RR) :circle(RR), table(colorr, high) {}
	void show(void)
	{
		table::show();
		circle::show();
		printf("\n");
	}
};

int main(void)
{
	double RR, high;
	char color[100];
	scanf_s("%lf", &RR);
	scanf_s("%lf", &high);
	getchar();
	scanf_s("%s", color, 100);
	roundtable R(color, high, RR);
	R.show();
	return 0;
}