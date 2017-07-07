/**********************************************
题目大意：
给出一个旋律，用n个数字[1,88]表示其音符，求它的最长的主题长度;
一个旋律的主题是一段至少出现过两次的不重叠音乐片段;
重复出现也包括一段音乐全体加上某个数后再次出现(如1 2 3 4 5和5 6 7 8 9为同一个音乐片段，全部+4);
主题长度至少为5,无解输出0;

算法分析：
给定一个字符串，求最长重复子串，这两个子串不能重叠;
先用后缀数组求出height数组;
利用height数组把排序后的后缀分成若干组，其中每组的后缀之间的height值都不小于k;
但由于这题目要求子串间不能重叠，因此采用二分答案的方法;
根据排序好的相邻后缀的关系，比较它们之间的距离差是否大于答案即可;

有希望成为最长公共前缀不小于k的两个后缀一定在同一组;
然后对于每组后缀，只须判断每个后缀的sa值的最大值和最小值之差是否不小于k;
如果有一组满足，则说明存在，否则不存在;
***********************************************/
#include<iostream>  
#include<cstring>  
#include<cstdlib>  
#include<cstdio>  
#include<climits>  
using namespace std;

const int N = 20010;
const int M = 190;//r数组的最大值  

#define F(x) ((x)/3+((x)%3==1?0:tb))  
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)  

int wa[N], wb[N], wv[N], _ws[M];

int c0(int *r, int a, int b)
{
	return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}

int c12(int k, int *r, int a, int b)
{
	if (k == 2)
		return r[a]<r[b] || r[a] == r[b] && c12(1, r, a + 1, b + 1);
	else
		return r[a]<r[b] || r[a] == r[b] && wv[a + 1]<wv[b + 1];
}

void sort(int *r, int *a, int *b, int n, int m)
{
	for (int i = 0; i<n; i++)
		wv[i] = r[a[i]];
	for (int i = 0; i<m; i++)
		_ws[i] = 0;
	for (int i = 0; i<n; i++)
		_ws[wv[i]]++;
	for (int i = 1; i<m; i++)
		_ws[i] += _ws[i - 1];
	for (int i = n - 1; i >= 0; i--)
		b[--_ws[wv[i]]] = a[i];
	return;
}

void dc3(int *r, int *sa, int n, int m)
{
	int i, j, *rn = r + n, *san = sa + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
	r[n] = r[n + 1] = 0;
	for (i = 0; i<n; i++)
	{
		if (i % 3 != 0)
			wa[tbc++] = i;
	}
	sort(r + 2, wa, wb, tbc, m);
	sort(r + 1, wb, wa, tbc, m);
	sort(r, wa, wb, tbc, m);
	for (p = 1, rn[F(wb[0])] = 0, i = 1; i<tbc; i++)
	{
		rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
	}
	if (p<tbc)
		dc3(rn, san, tbc, p);
	else
	{
		for (i = 0; i<tbc; i++)
			san[rn[i]] = i;
	}
	for (i = 0; i<tbc; i++)
	{
		if (san[i]<tb)
			wb[ta++] = san[i] * 3;
	}
	if (n % 3 == 1)
		wb[ta++] = n - 1;
	sort(r, wb, wa, ta, m);
	for (i = 0; i<tbc; i++)
		wv[wb[i] = G(san[i])] = i;
	for (i = 0, j = 0, p = 0; i<ta && j<tbc; p++)
	{
		sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
	}
	for (; i<ta; p++)
		sa[p] = wa[i++];
	for (; j<tbc; p++)
		sa[p] = wb[j++];
	return;
}

int rankk[N], height[N];

void calheight(int *r, int *sa, int n)
{
	int i, j, k = 0;
	for (i = 1; i <= n; i++)
		rankk[sa[i]] = i;
	for (i = 0; i<n; height[rankk[i++]] = k)
	{
		for (k ? k-- : 0, j = sa[rankk[i] - 1]; r[i + k] == r[j + k]; k++);
	}
	return;
}

int check(int *sa, int n, int k)
{
	int i, max = sa[1], min = sa[1];
	for (i = 2; i <= n; i++)
	{
		if (height[i]<k)
			max = min = sa[i];
		else
		{
			if (sa[i]<min)
				min = sa[i];
			if (sa[i]>max)
				max = sa[i];
			if (max - min>k)
				return(1);
		}
	}
	return(0);
}

int r[N * 3], sa[N * 3];

int main()
{
	int k, n;
	int min, mid, max;
	while (scanf("%d", &n) && n)
	{
		int j = 0;
		for (int i = 0; i<n; i++)
		{
			scanf("%d", &k);
			r[i] = k - j + 100;
			j = k;
		}
		r[n] = 0;
		dc3(r, sa, n + 1, M);
		calheight(r, sa, n);
		min = 1;
		max = n >> 1;
		while (min <= max)
		{
			mid = (min + max) >> 1;
			if (check(sa, n, mid))
				min = mid + 1;
			else
				max = mid - 1;
		}
		if (max >= 4)
			printf("%d\n", max + 1);
		else
			printf("0\n");
	}
	return 0;
}