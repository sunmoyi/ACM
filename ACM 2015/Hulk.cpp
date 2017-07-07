#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str1[100] = "I hate ";
char str2[100] = "I love ";
char str3[100] = "that";
char str4[100] = "it";

int main (void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i % 2)
				printf("%s", str1);
			else
				printf("%s", str2);

			if (i != n)
				printf("%s ", str3);
			else
				printf("%s\n", str4);
		}
	}
	return 0;
}

/*
1 4
1 1 3
1 1 1 2
1 1 1 1

1 4
1 2 2
1 1 1 2
1 1 1 1




*/