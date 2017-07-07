#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans;
int year, month, dayy;
int year1, month1, dayy1;

int main(void)
{
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf("%d %d %d", &year, &month, &dayy);
			scanf("%d %d %d", &year1, &month1, &dayy1);
			if (year < year1)
				printf("javaman\n");
			else if (year == year1 && month < month1)
				printf("javaman\n");
			else if (year == year1 && month == month1 && dayy < dayy1)
				printf("javaman\n");
			else if (year == year1 && month == month1 && dayy == dayy1)
				printf("same\n");
			else
				printf("cpcs\n");
		}
	}
	return 0;
}