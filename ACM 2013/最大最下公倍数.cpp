#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

int main(){
	int T;
	scanf("%d", &T);
	ll n, num;
	while (T--){
		scanf("%lld", &n);
		if (n <= 2){
			printf("2\n");
			continue;
		}
		else if (n % 2)
			num = n*(n - 1)*(n - 2);
		else if (n % 3 == 0)
			num = (n - 1)*(n - 2)*(n - 3);
		else
			num = n*(n - 1)*(n - 3);
		printf("%lld\n", num);
	}
	return 0;
}
	