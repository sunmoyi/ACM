#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int chance, left, win, lose;
char s1[10000], s2[10000];

void gress(char ch)
{
	int bad = 1;
	for (int i = 0; i < strlen(s1); i++)
	{
		if (s1[i] == ch)
		{
			left--;
			s1[i] = ' ';
			bad = 0;
		}
	}
	if (bad)
		chance--;
	if (left == 0)
		win = 1;
	if (chance == 0)
		lose = 1;
}

int main(void)
{
	int rnd;
	while (scanf("%d", &rnd) != EOF && rnd != -1)
	{
		scanf("%s%s", s1, s2);
		printf("Round %d\n", rnd);
		win = lose = 0;
		left = strlen(s1);
		chance = 7;
		for (int i = 0; i < strlen(s2); i++)
		{
			gress(s2[i]);
			if (win || lose)
				break;
		}
		if (win)
			printf("You win.\n");
		else if (lose)
			printf("You lose.\n");
		else
			printf("You chickened out.\n");
	}
	return 0;
}
