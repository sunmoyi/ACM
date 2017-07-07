#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

struct Trie {
	int next[520 * 64][256], fail[520 * 64], end[520 * 64];
	int root, L;
	int newnode()
	{
		for (int i = 0; i < 256; i++)
			next[L][i] = -1;
		end[L++] = -1;
		return L - 1;
	}
	void init()
	{
		L = 0;
		root = newnode();
	}
	void insert(unsigned char *buf, int len, int id)
	{
		int now = root;
		for (int i = 0; i < len; i++)
		{
			if (next[now][buf[i]] == -1)
				next[now][buf[i]] = newnode();
			now = next[now][buf[i]];
		}
		end[now] = id;
	}
	void build()
	{
		queue<int>Q;
		fail[root] = root;
		for (int i = 0; i < 256; i++)
		{
			if (next[root][i] == -1)
				next[root][i] = root;
			else
			{
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		}
		while (!Q.empty())
		{
			int now = Q.front();
			Q.pop();
			for (int i = 0; i < 256; i++)
			{
				if (next[now][i] == -1)
					next[now][i] = next[fail[now]][i];
				else
				{
					fail[next[now][i]] = next[fail[now]][i];
					Q.push(next[now][i]);
				}
			}
		}
	}
	bool used[520];
	int query(unsigned char *buf, int len, int n)
	{
		memset(used, false, sizeof(used));
		int now = root;
		for (int i = 0; i < len; i++)
		{
			now = next[now][buf[i]];
			int temp = now;
			while (temp != root)
			{
				if (end[temp] != -1)
					used[end[temp]] = true;
				temp = fail[temp];
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++)
			if (used[i])
				res++;
		return res;
	}
};

unsigned char buf[2050];
int tot;
char str[4000];
unsigned char s[4000];
unsigned char Get(char ch)
{
	if (ch >= 'A'&&ch <= 'Z')return ch - 'A';
	if (ch >= 'a'&&ch <= 'z')return ch - 'a' + 26;
	if (ch >= '0'&&ch <= '9')return ch - '0' + 52;
	if (ch == '+')return 62;
	else return 63;
}
void change(unsigned char str[], int len)
{
	int t = 0;
	for (int i = 0; i<len; i += 4)
	{
		buf[t++] = ((str[i] << 2) | (str[i + 1] >> 4));
		if (i + 2 < len)
			buf[t++] = ((str[i + 1] << 4) | (str[i + 2] >> 2));
		if (i + 3 < len)
			buf[t++] = ((str[i + 2] << 6) | str[i + 3]);
	}
	tot = t;
}
Trie ac;
int main()
{
	int n, m;
	while (scanf("%d", &n) == 1)
	{
		ac.init();
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str);
			int len = strlen(str);
			while (str[len - 1] == '=')
				len--;
			for (int j = 0; j < len; j++)
			{
				s[j] = Get(str[j]);
			}
			change(s, len);
			ac.insert(buf, tot, i);
		}
		ac.build();
		scanf("%d", &m);
		while (m--)
		{
			scanf("%s", str);
			int len = strlen(str);
			while (str[len - 1] == '=')len--;
			for (int j = 0; j < len; j++)
				s[j] = Get(str[j]);
			change(s, len);
			printf("%d\n", ac.query(buf, tot, n));
		}
		printf("\n");
	}
	return 0;
}