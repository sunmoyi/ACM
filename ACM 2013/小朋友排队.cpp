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
		for (i = 1; i < M; ++i)//���N���ۼ�  
			sum[i] = sum[i - 1] + i;
		for (i = 0; i < n; ++i){  //��ǰ�����ߵ��γɵ��������
			cin >> a[i];  //ȷ��ÿ���㶼������
			add(a[i] + 1);
			b[i] = i + 1 - getsum(a[i] + 1);//b[i]��������ǵ�i��������ߵ������ɵ�����Եĸ���
		}                                   //   i+ 1 ��ʾi��λ��  getsum��a[i] + 1����ʾ����ǰi���в���a[i]��������Եĸ���
		memset(c, 0, sizeof(c));
		LL res = 0;
		for (int i = n - 1; i >= 0; --i){ //��ǰ����ұߵ��γɵ��������
			add(a[i] + 1);                // �ٴμ���c[] ���������a[i]�ұ�����Եĸ���
			res += sum[b[i] + getsum(a[i])];//���+�ұߵĺͱ�ʾ�ܵ�����Եĸ��� ��֮ǰ��õı����ҵ���Ӧ������
		}
		//cout <<res <<endl;
		printf("%lld\n", res);
	}
	return 0;
}
