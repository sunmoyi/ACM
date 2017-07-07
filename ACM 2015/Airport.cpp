#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define PI acos(-1.0)
#define esp 1e-6

using namespace std;

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y){}
};

typedef Point Vector;

Vector operator - (Point A, Point B)
{
	return Vector(A.x - B.x, A.y - B.y);
}

double Cross(Vector A, Vector B)
{
	return A.x * B.y - B.x * A.y;
}

bool operator < (Point A, Point B)
{
	return A.x < B.x || (A.x == B.x && A.y < B.y);
}

bool operator == (Point p1, Point p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

// 点集凸包
// 如果不希望在凸包的边上有输入点，把两个 <= 改成 <
// 如果不介意点集被修改，可以改成传递引用
vector<Point> ConvexHull(vector<Point> p)
{
	// 预处理，删除重复点
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());

	int n = p.size();
	int m = 0;
	vector<Point> ch(n + 1);
	for (int i = 0; i < n; i++) 
	{
		while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
			m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--) 
	{

		while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
			m--;
		ch[m++] = p[i];
	}
	if (n > 1) m--;
	ch.resize(m);
	return ch;
}

void getlinegeneralequation(Point p1, Point p2, double &a, double &b, double &c)
{
	a = p2.y - p1.y;
	b = p1.x - p2.x;
	c = -a * p1.x - b * p1.y;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int icase = 1; icase <= T; icase++)
	{
		int n;
		scanf("%d", &n);
		vector<Point>P;
		double sumx = 0, sumy = 0;
		for (int i = 0; i < n; i++)
		{
			double x, y;
			scanf("%lf%lf", &x, &y);
			sumx += x, sumy += y;
			P.push_back(Point(x, y));
		}
		vector<Point>ch = ConvexHull(P);
		int m = ch.size();
		//printf("%d\n", m);
		double ans = 0x3f3f3f3f;
		if (m <= 2)
			ans = 0;
		else
		{
			for (int i = 0; i < ch.size(); i++)
			{
				double a, b, c;
				getlinegeneralequation(ch[i], ch[(i + 1) % ch.size()], a, b, c);
				ans = min(ans, fabs(a*sumx + b*sumy + c*n) / sqrt(a*a + b*b));
			}
		}
		printf("Case #%d: %.3lf\n", icase, ans / n);
	}
	return 0;
}