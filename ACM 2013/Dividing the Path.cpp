#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>

#define INF (1 << 30)
#define maxl 10000010
#define maxn 1010

using namespace std;

int F[maxl];
int cowthere[maxl];
int N, L, A, B;

struct Fx {
	int x, f;
	bool operator < (const Fx &a)const
	{
		return f > a.f;
	}
	Fx(int xx = 0, int ff = 0) :x(xx), f(ff) {}
};

priority_queue<Fx>qFx;

int main(void)
{
	cin >> N >> L;
	cin >> A >> B;
	A <<= 1; B <<= 1;
	memset(cowthere, 0, sizeof(cowthere));
	for (int i = 1; i <= N; i++)
	{
		int s, e;
		cin >> s >> e;
		++cowthere[s + 1];
		--cowthere[e];
	}
	int incows = 0;
	for (int i = 1; i <= i; i++)
	{
		F[i] = INF;
		incows += cowthere[i];
		cowthere[i] = incows > 0;
	}
	for (int i = A; i <= B; i += 2)
	{
		if (!cowthere[i])
		{
			F[i] = 1;
			if (i <= B + 2 - A)
				qFx.push(Fx(i, F[i]));
		}
	}
	for (int i = B + 2; i <= L; i += 2)
	{
		if (!cowthere[i])
		{
			Fx fx;
			while (!qFx.empty())
			{
				fx = qFx.top();
				if (fx.x < i - B)
					qFx.pop();
				else
					break;
			}
			if (!qFx.empty())
				F[i] = fx.f + 1;
		}
		if (F[i - A + 2] != INF)
			qFx.push(Fx(i - A + 2, F[i - A + 2]));
	}
	if (F[L] == INF)
		cout << -1 << endl;
	else
		cout << F[L] << endl;
	return 0;
}