#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 105
#define MOD 363520489

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		long long f[MAX][MAX] = { 0 };
		int k, l, i, j;
		cin >> k >> l;
		for (i = 0; i < k; ++i){
			f[1][i] = 1;
		}
		for (i = 2; i <= l; ++i){
			for (j = 0; j < k; ++j){
				int p;
				for (p = 0; p < k; ++p)
				{
					if (p != j - 1 && p != j + 1)
					{
						f[i][j] += f[i - 1][p] % MOD;
						f[i][j] %= MOD;
					}
				}
			}
		}

		long long sum = 0;
		for (i = 1; i < k; ++i){
			sum += f[l][i] % MOD;
			sum %= MOD;
		}

		cout << sum << endl;
	}

	return 0;
}
