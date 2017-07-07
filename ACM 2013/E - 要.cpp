#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char A[10000];
char B[10000];
char C[10000];
char D[10000];
int len1, len2, len3, len4;
char flag;
int flagg;

bool check(void)
{
	if (len1 >= 2 * len2 && len1 >= 2 * len3 && len1 >= 2 * len4)
	{
		flag = 'A';
		flagg++;
	}
	if (len2 >= 2 * len1 && len2 >= 2 * len3 && len2 >= 2 * len4)
	{
		flag = 'B';
		flagg++;;
	}
	if (len3 >= 2 * len2 && len3 >= 2 * len1 && len3 >= 2 * len4)
	{
		flag = 'C';
		flagg++;
	}
	if (len4 >= 2 * len2 && len4 >= 2 * len3 && len4 >= 2 * len1)
	{
		flag = 'D';
		flagg++;
	}
	if (len1 <= len2 / 2 && len1 <= len3 / 2 && len1 <= len4 / 2)
	{
		flag = 'A';
		flagg++;
	}
	if (len2 <= len1 / 2 && len2 <= len3 / 2 && len2 <= len4 / 2)
	{
		flag = 'B';
		flagg++;
	}
	if (len3 <= len2 / 2 && len3 <= len1 / 2 && len3 <= len4 / 2)
	{
		flag = 'C';
		flagg++;
	}
	if (len4 <= len2 / 2 && len4 <= len3 / 2 && len4 <= len1 / 2)
	{
		flag = 'D';
		flagg++;
	}
	if (flagg != 1)
		return false;
	return  true;
}

int main(void)
{
	while (scanf("%s", A) != EOF)
	{
		flagg = 0;
		scanf("%s", B);
		scanf("%s", C);
		scanf("%s", D);
		len1 = strlen(A) - 2;
		len2 = strlen(B) - 2;
		len3 = strlen(C) - 2;
		len4 = strlen(D) - 2;
		if (check())
			printf("%c\n", flag);
		else
			printf("C\n");
	}
	return 0;
}