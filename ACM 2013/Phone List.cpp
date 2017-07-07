#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char phone[10000][11];
int cmp(const void* a, const void* b)
{
	return strcmp((char*)a, (char*)b);
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int i, n;
		bool flag = false;
		scanf("%d", &n);
		for (i = 0; i<n; i++)
		{
			scanf("%s", phone[i]);
		}
		qsort(phone, n, sizeof(phone[0]), cmp);
		for (i = 0; i<n - 1; i++)
		{
			if (strncmp(phone[i], phone[i + 1], strlen(phone[i])) == 0)
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}