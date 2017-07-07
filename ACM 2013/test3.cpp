#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;


int main(void)
{
	char a[100];
	while (scanf_s("%s", a, 99) != EOF)
	{
		printf("c_give(\"");
		for (int i = 0; i < strlen(a); i++)
		{
			if (a[i] == ' ')
				break;
			printf("%c", a[i]);
		}
		printf("\",10)\n");
	}
	return 0;
}