#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define LL long long
const int M = 1e6 + 5;
using namespace std;

LL c[M], sum[M], a[M], b[M];

LL bit(LL x){
	return x & -x;
}
void add(LL x){
	while (x < M){
		c[x]++;
		x += bit(x);
	}
}

LL getsum(LL x){
	LL sum = 0;
	while (x){
		sum += c[x];
		x -= bit(x);
	}
	return sum;
}

int main(){
	LL n, i;
	int T;
	scanf_s("%d", &T);
	while (T--){
		cin >> n;
		for (i = 1; i < M; ++i)//打表N的累加  
			sum[i] = sum[i - 1] + i;
		for (i = 0; i < n; ++i){  //当前点跟左边点形成的逆序对数
			cin >> a[i];  //确保每个点都被更新
			add(a[i] + 1);
			b[i] = i + 1 - getsum(a[i] + 1);//b[i]所保存的是第i个数与左边的数构成的逆序对的个数
		}                                   //   i+ 1 表示i的位置  getsum（a[i] + 1）表示的是前i项中不与a[i]构成逆序对的个数
		memset(c, 0, sizeof(c));
		LL res = 0;
		for (int i = n - 1; i >= 0; --i){ //当前点跟右边点形成的逆序对数
			add(a[i] + 1);                // 再次计算c[] 计算出的是a[i]右边逆序对的个数
			res += sum[b[i] + getsum(a[i])];//左边+右边的和表示总的逆序对的个数 在之前打好的表中找到对应的数；
		}
		//cout <<res <<endl;
		printf("%lld\n", res);
	}
	return 0;
}
