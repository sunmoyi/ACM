#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5050

using namespace std;

int ans[maxn];
struct point {
	int x, y;
	point(int x = 0, int y = 0) :x(x), y(y) {}
};

point operator - (point a, point b)
{
	return point(a.x - b.x, a.y - b.y);
}

point operator + (point a, point b)
{
	return point(a.x + b.x, a.y + b.y);
}

int  dot(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}

int cross(point a, point b)
{
	return a.x * b.y - b.x * a.y;
}

struct Line {
	point s, e;
	Line() {}
	Line(point _s, point _e)
	{
		s = _s;
		e = _e;
	}
}line[maxn];

int mult(point p0, point p1, point p2)
{
	return cross((p1 - p0), (p2 - p0));
}

int main(void)
{
	int n, m, x1, y1, x2, y2;
	bool frist = true;
	while (scanf("%d", &n) != EOF && n)
	{
		if (frist)
			frist = false;
		else
			printf("\n");
		scanf("%d %d %d %d %d", &m, &x1, &y1, &x2, &y2);
		int ui, li;
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d", &ui, &li);
			line[i] = Line(point(ui, y1), point(li, y2));
		}
		line[n] = Line(point(x2, y1), point(x2, y2));
		int x, y;
		point p;
		memset(ans, 0, sizeof(ans));
		while (m--)
		{
			scanf("%d %d", &x, &y);
			p = point(x, y);
			int l = 0, r = n;
			int temp;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (mult(p, line[mid].s, line[mid].e) < 0)
				{
					temp = mid;
					r = mid - 1;
				}
				else
					l = mid + 1;
			}
			ans[temp]++;
		}
		for (int i = 0; i <= n; i++)
			printf("%d: %d\n", i, ans[i]);
	}
	return 0;
}