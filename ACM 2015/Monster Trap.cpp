#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define eps 1e-12
#define maxn 210
#define maxm 110

using namespace std;

double dcmp(double x)
{
	if (fabs(x) < eps)
		return 0;
	return x > 0 ? 1 : -1;
}

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y){}
};

typedef Point Vector;

Vector operator + (Point A, Point B)
{
	return Vector(A.x + B.x, A.y + B.y);
}

Vector operator -(Point A, Point B)
{
	return Vector(A.x - B.x, A.y - B.y);
}

Vector operator * (Point A, double k)
{
	return Vector(A.x * k, A.y * k);
}

Vector operator / (Point A, double k)
{
	return Vector(A.x / k, A.y / k);
}

double Cross(Vector A, Vector B)
{
	return A.x * B.y - B.x * A.y;
}

double Dot(Vector A, Vector B)
{
	return A.x * B.x + A.y * B.y;
}

double Lenth(Vector A)
{
	return sqrt(Dot(A, A));
}

bool operator < (Point A, Point B)
{
	return A.x < B.x || (A.x == B.x && A.y < B.y);
}

bool operator == (Point A, Point B)
{
	return A.x == B.x && A.y == B.y;
}

bool SegmentProperIntersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
	double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
		c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
	return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}

bool OnSegment(const Point& p, const Point& a1, const Point& a2) {
	return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

int V;
int G[maxn][maxn], vis[maxn];
int n;
Point p1[maxm], p2[maxm];

bool dfs(int u)
{
	if (u == 1)
		return true;
	vis[u] = 1;
	for (int v = 0; v < V; v++)
		if (G[u][v] && !vis[v] && dfs(v))
			return true;
	return false;
}

// 在任何一条线段的中间（在端点不算）
bool OnAnySegment(Point p) {
	for (int i = 0; i < n; i++)
		if (OnSegment(p, p1[i], p2[i])) return true;
	return false;
}

// 与任何一条线段规范相交
bool IntersectWithAnySegment(Point a, Point b) {
	for (int i = 0; i < n; i++)
		if (SegmentProperIntersection(a, b, p1[i], p2[i])) return true;
	return false;
}

bool find_path()
{
	vector<Point>vertices;
	vertices.push_back(Point(0, 0));
	vertices.push_back(Point(1e5, 1e5));
	for (int i = 0; i < n; i++)
	{
		if (!OnAnySegment(p1[i]))
			vertices.push_back(p1[i]);
		if (!OnAnySegment(p2[i]))
			vertices.push_back(p2[i]);
	}
	V = vertices.size();
	memset(G, 0, sizeof(G));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < V; i++)
		for (int j = i + 1; j < V; j++)
			if (!IntersectWithAnySegment(vertices[i], vertices[j]))
				G[i][j] = G[j][i] = 1;
	return dfs(0);
}

int main(void)
{
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i < n; i++)
		{
			double x1, y1, x2, y2;
			scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
			Point a = Point(x1, y1);
			Point b = Point(x2, y2);
			Vector v = b - a;
			v = v / Lenth(v);
			p1[i] = a - v * 1e-6;
			p2[i] = b + v * 1e-6;
		}
		if (find_path())
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}