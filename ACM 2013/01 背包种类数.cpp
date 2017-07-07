#include <iostream> 
#define MAX 41
using namespace std;
 
int main()
{ 
	int n,i,j,input; 
	int sum[MAX];
	memset(sum, 0, sizeof(sum));
	cin >> n; 
	sum[0] = 1;
	for(i=0;i<n;i++)
	{ 
		cin >> input; 
		for (j = 40; j >= 1; j--)
		{
			if(j - input >= 0)
				sum[j] += sum[j - input];
		}
	} cout << sum[40] << endl; 
	return 0;
}