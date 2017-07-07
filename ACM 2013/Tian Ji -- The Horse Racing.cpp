/*#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;

int tianji1[1005];
int king[1005];
int n, m;

int main(void)
{
	while (scanf_s("%d", &n) != EOF && n)
	{
		int sum1 = 0, sum2 = 0;
		int count1 = 0, count2 = 0;
		for (int i = 0; i < n; i++)
			scanf_s("%d", &tianji1[i]);
		for (int i = 0; i < n; i++)
			scanf_s("%d", &king[i]);

		sort(king, king + n);
		sort(tianji1, tianji1 + n);
		
		for (int i = 0; i < n; i++)
		{
			int j;
			for (j = 0; j < n; j++)
			{
				if (tianji1[j] > king[i])
				{
					tianji1[j] = INT_MIN;
					count1++;
					break;
				}
				else if (tianji1[j] == king[i])
				{
					tianji1[j] = INT_MIN;
					break;
				}
			}
			if (j == n)
				count2++;
		}
		sum1 = (count1 - count2) * 200;
		
		count1 = 0; count2 = 0;
		for (int i = 0; i < n; i++)
		{
			int j;
			for (j = 0; j < n; j++)
			{
				if (tianji1[j] > king[i])
				{
					tianji1[j] = INT_MIN;
					count1++;
					break;
				}
			}
			if (j == n)
				count2++;
		}
		sum2 = (count1 - count2) * 200;
		if (sum1 > sum2)
			printf("%d\n", sum1);
		else
			printf("%d\n", sum2);
	}
	return 0;
}
*/

#include <stdio.h>  
#include <algorithm>  
using namespace std;
int T[1002], K[1002], n, win, lose;
void read()
{
	for (int i = 0; i<n; i++)
		scanf_s("%d", &T[i]);
	for (int i = 0; i<n; i++)
		scanf_s("%d", &K[i]);
	sort(T, T + n);
	sort(K, K + n);
}
void race()
{
	win = lose = 0;
	int t_slow = 0, t_fast = n - 1;
	int k_slow = 0, k_fast = n - 1;
	while (t_slow <= t_fast)
	{
		if (T[t_slow] > K[k_slow])        
		{
			win++;
			t_slow++;
			k_slow++;
		}
		else if (T[t_slow] < K[k_slow])     
		{
			lose++;
			t_slow++;
			k_fast--;
		}
		else                              
		{
			if (T[t_fast] > K[k_fast])    
			{
				win++;
				t_fast--;
				k_fast--;
			}
			else                           
			{
				if (T[t_slow] < K[k_fast])
					lose++;
				t_slow++;
				k_fast--;
			}
		}
	}
}
int main()
{  
	while (scanf_s("%d", &n), n)
	{
		read();
		race();
		printf("%d\n", 200 * (win - lose));
	}
	return 0;
}