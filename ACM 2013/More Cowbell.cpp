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
	if (n <= k)//�����������Ŀ����������  
	{
		cout << val[n] << endl;//ȡ���ֵ  
	}
	else if (cn == 1 && yn == 0)//�����������Ŀ�����������  
	{
		cout << val[n] << endl;//ȡ���ֵ  
	}
	else if (cn == 1 && yn)//��һ���ֵĶ���Ҫ��������һ��  
	{
		res = val[n];
		for (i = 1; i <= yn; i++)
		{
			res = max(res, val[i] + val[2 * yn - i + 1]);
		}
		cout << res << endl;
	}
	else//���ж�����Ҫ��������һ��  
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