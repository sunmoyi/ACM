#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int rot[8][7] =
{
	0, 2, 6, 11, 15, 20, 22,//A
	1, 3, 8, 12, 17, 21, 23,//B
	10, 9, 8, 7, 6, 5, 4,//C
	19, 18, 17, 16, 15, 14, 13,//D
	23, 21, 17, 12, 8, 3, 1,//E
	22, 20, 15, 11, 6, 2, 0,//F
	13, 14, 15, 16, 17, 18, 19,//G
	4, 5, 6, 7, 8, 9, 10//H
};

int res[] = { 5,4,7,6,1,0,3,2 };
int depth;

bool check(char s[])
{
	char ch = s[6];
	for (int i = 0; i < 3; i++)
		if (ch != s[i + 6] || ch != s[i + 15])
			return false;
	return ch == s[11] && ch == s[12];
}

void rotate(int k, char s[])
{
	char ch = s[rot[k][0]];
	for (int i = 0; i<6; i++)
		s[rot[k][i]] = s[rot[k][i + 1]];
	s[rot[k][6]] = ch;
}

bool IDAstar(int k, char st[], char op[], int la)
{
	int cnt[4];
	cnt[1] = cnt[2] = cnt[3] = 0;
	for (int i = 0; i<3; i++)
		cnt[st[i + 6] - '0']++, cnt[st[15 + i] - '0']++;
	cnt[st[11] - '0']++, cnt[st[12] - '0']++;
	cnt[0] = max(max(cnt[1], cnt[2]), cnt[3]);
	if (k + 8 - cnt[0] >= depth)
		return false;
	for (int i = 0; i < 8; i++)
	{
		if (la != -1 && res[i] == la)
			continue;
		op[k] = 'A' + i;
		rotate(i, st);
		if (check(st))
		{
			op[k + 1] = '\0';
			return true;
		}
		else if (IDAstar(k + 1, st, op, i))
			return true;
		rotate(res[i], st);
	}
	return false;
}

int main(void)
{
	char ch;
	while (scanf(" %c", &ch), ch != '0')
	{
		char st[25];
		st[0] = ch;
		for (int i = 1; i < 24; i++)
			scanf(" %c", &st[i]);
		depth = 1;
		if (check(st))
			printf("No moves needed\n%c\n", st[6]);
		else
		{
			char op[200];
			op[0] = 0;
			while (!IDAstar(0, st, op, -1))
				depth++;
			printf("%s\n%c\n", op, st[6]);
		}
	}
	return 0;
}