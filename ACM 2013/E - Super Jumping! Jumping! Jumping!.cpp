#include<iostream>

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF&&n)
	{
		int dp[1010] = { 0 };//最大和
		int b[1010] = { 0 };//当前数
		for (int i = 0; i<n; i++)
		{
			int temp;
			int max = -1;
			scanf("%d", &temp);
			b[i] = temp;
			bool find = false;
			for (int j = 0; j<i; j++)
			{
				if ((b[j] < temp) && (dp[j] + temp > max))
				{
					max = dp[j] + temp;
					find = true;
				}
			}
			if (find) 
				dp[i] = max;
			else 
				dp[i] = b[i];
		}

		int out = -1;
		for (int i = 0; i<n; i++)
		{
			if (out < dp[i]) 
				out = dp[i];
		}
		cout << out << endl;
	}
	return 0;
}