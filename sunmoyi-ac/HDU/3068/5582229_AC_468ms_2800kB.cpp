#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 220009

using namespace std;

char strin[maxn];
char strout[maxn];
int p[maxn];

int proc(void)
{
	int len = 1;
	strout[0] = '$';
	int i = 0;
	while (strin[i] !='\0')
	{
		strout[len++] = '#';
		strout[len++] = strin[i];
		i++;
	}
	strout[len++] = '#';
	strout[len] = 0;
	return len;
}

void Manacher(int len)
{
	int mx = 0, id = 0;
	for (int i = 0; i < len; i++)
	{
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while (strout[i + p[i]] == strout[i - p[i]])
			p[i]++;
		if (i + p[i] > mx)
		{
			mx = i + p[i];
			id = i;
		}
	}
}

int main(void)
{
	while (scanf_s("%s", strin, maxn - 1) != EOF)
	{
		int len = proc();
		Manacher(len);
		int maxx = 1;
		for (int i = 0; i < len; i++)
			maxx = max(maxx, p[i]);
		printf("%d\n", maxx - 1);
	}
	return 0;
}