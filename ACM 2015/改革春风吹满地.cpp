#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

struct vector {
	double x, y;
	vector(double x = 0, double y = 0) :x(x), y(y) {}
};

vector operator +(vector &a, vector &b)
{
	return vector(a.x + b.x, a.y + b.y);
}

vector operator - (vector &a, vector&b)
{
	return vector(a.x - b.x, a.y - b.y);
}

vector operator * (double k, vector &a)
{
	return vector(k * a.x, k * a.y);
}

double operator * (vector &a, vector &b)
{
	return a.x * b.x + a.y * b.y;
}

double len (vector &p)
{
	return sqrt(p * p);
}
//单位化
vector unit(vector &a)
{
	return 1 / len(a) * a;
}
//点积和上面的重载 * 一个含义
double dot(vector &a, vector &b)
{
	return a.x * b.x + a.y * b.y;
}
//a在b上的投影
double project(vector &a, vector &b)
{
	return dot(a, unit(b));
}
//叉乘
double operator ^ (vector &a, vector & b)
{
	return a.x * b.y - b.x * a.y;
}
//重载小于号 直接sort排序之后所有的点就是逆时针顺序的  
bool operator < (vector&a, vector&b)
{
	return (a ^ b) > 0;
}

vector vec[500];

int main(void)
{
	double sum;
	int num;
	while (scanf("%d", &num) != EOF && num)
	{
		sum = 0;
		scanf("%lf %lf", &vec[1].x, &vec[1].y);
		for (int i = 2; i <= num; i++)
		{
			scanf("%lf %lf", &vec[i].x, &vec[i].y);
			sum += (vec[i - 1] ^ vec[i]) / 2;
		}
		sum += (vec[num] ^ vec[1]) / 2;
		printf("%.1lf\n", sum);
	}
	return 0;
}