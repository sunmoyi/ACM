#include<cstdio>
#include<cstring> 
#include<algorithm> 
#include<iostream> 
#include<cmath> 
#define MAXN (100+10) 

using namespace std; 

class vector { 
public: 
	int x,y;
	vector(int _x = 0, int _y = 0):x(_x),y(_y){} 
	friend int operator^(const vector a,const vector b)  
	{ 
		return a.x*b.y-a.y*b.x;
	} 
}node[MAXN];  

int n; 

int main()
{ 
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			cin >> node[i].x >> node[i].y;
		node[n + 1] = node[1];
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans += node[i] ^ node[i + 1];
		ans = abs(ans);
		printf("%d\n", int(round(double(ans) / 2)));
	}
	return 0;  
} 
