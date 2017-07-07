#include <iostream>    
#include <algorithm>    
#include <cmath>    
#include <vector>    
#include <string>    
#include <cstring>  
#include <queue>  
#include <map>  
using namespace std;
typedef long long ll;

int n, k;
int val[100005];

int main()
{
	//freopen("i.txt", "r", stdin);  
	//freopen("o.txt", "w", stdout);  

	int i, j;
	int cn, yn;
	int res = 0;
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
	}
	cn = n / k;
	yn = n%k;
	if (n <= k)//如果东西的数目比箱子数少  
	{
		cout << val[n] << endl;//取最大值  
	}
	else if (cn == 1 && yn == 0)//如果东西的数目和箱子数相等  
	{
		cout << val[n] << endl;//取最大值  
	}
	else if (cn == 1 && yn)//有一部分的东西要两个放在一起  
	{
		res = val[n];
		for (i = 1; i <= yn; i++)
		{
			res = max(res, val[i] + val[2 * yn - i + 1]);
		}
		cout << res << endl;
	}
	else//所有东西都要两个放在一起  
	{
		res = val[n];
		for (i = 1; i <= n / 2; i++)
		{
			res = max(res, val[i] + val[n - i + 1]);
		}
		cout << res << endl;
	}
	//system("pause");  
	return 0;
}