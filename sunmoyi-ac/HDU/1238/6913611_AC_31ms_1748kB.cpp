#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
#include<vector>  
#include<map>  
#include<list>  
#include<cmath>  
#include<set>  
#include<queue>  
using namespace std;
typedef long long ll;
const int maxn = 100 + 5;
const int INF = 1000000000 + 5;
int T, n, l, r, f[maxn], f2[maxn];

struct node {
	char s[105];
	int len;
}a[maxn], b[maxn];
char s[maxn], s2[maxn];
void getFail(char* P, int* f)
{
	int m = strlen(P);
	f[0] = 0; f[1] = 0;
	for (int i = 1; i < m; i++) 
	{
		int j = f[i];
		while (j && P[i] != P[j])
			j = f[j];
		f[i + 1] = P[i] == P[j] ? j + 1 : 0;
	}
}
bool findd(char* T, char* P, int* f)
{
	int n = strlen(T), m = strlen(P);
	getFail(P, f);
	int j = 0;
	bool ok = false;
	for (int i = 0; i<n; i++)
	{
		while (j && P[j] != T[i]) 
			j = f[j];
		if (P[j] == T[i])
			j++;
		if (j == m)
		{
			ok = true; 
			break; 
		}
	}
	return ok;
}
int main() 
{
	scanf("%d", &T);
	while (T--) 
	{
		scanf("%d", &n);
		int min_Len = INF, min_id;
		for (int i = 0; i<n; i++) 
		{
			scanf("%s", a[i].s);
			a[i].len = strlen(a[i].s);
			if (min_Len > a[i].len)
			{
				min_Len = a[i].len;
				min_id = i;
			}
		}
		int ans = 0;
		for (int i = 0; i<min_Len; i++)
		{
			for (int j = min_Len - 1; j >= i; j--) 
			{
				int t = 0;
				for (int k = i; k <= j; k++)
					s[t++] = a[min_id].s[k];
				s[t] = '\0';
				t = 0;
				for (int k = j; k >= i; k--) 
					s2[t++] = a[min_id].s[k];
				s2[t] = '\0';
				bool ok = true;
				for (int k = 0; k<n; k++) 
				{
					if (!findd(a[k].s, s, f) && !findd(a[k].s, s2, f2)) 
					{ 
						ok = false; 
						break; 
					}
				}
				if (ok) ans = max(ans, j - i + 1);
				if (ok) break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}