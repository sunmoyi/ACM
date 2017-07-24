//
// Created by 孙启龙 on 2017/3/19.
//

#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
#define maxn 30
map<int,int> m;
int A[maxn];
char str[maxn];
int bitcount(int n) {
    return n == 0 ? 0: bitcount(n/2) + (n % 2);
}
int main() {
    int N;
    while(scanf("%d", &N) == 1 && N) {
        memset(A,0,sizeof(A));
        m.clear();
        for(int i = 0; i < N; i++) {
            scanf("%s", str);
            for(int j = 0; str[j] != '\0'; j++)
                A[i] ^= (1 << (str[j] - 'A'));
        }

        int n1 = N / 2, n2 = N - n1;

        for(int i = 0; i < (1 << n1); i++) {
            int x = 0;
            for(int j = 0; j < n1; j++)
                if(i & (1 << j))
                    x ^= A[j];
            if(!m.count(x) || bitcount(m[x]) < bitcount(i))
                m[x] = i;
        }

        int ans = 0;
        for(int i = 0; i < (1 << n2); i++) {
            int x = 0;
            for(int j = 0; j < n2; j++)
                if(i & (1 << j))
                    x ^= A[n1+j];
            if(m.count(x) && bitcount(ans) < bitcount(m[x]) + bitcount(i))
                ans = (i << n1) + m[x];
        }
        printf("%d\n",bitcount(ans));
        for(int i = 0; i < N; i++)
            if(ans & (1 << i))
                printf("%d ", i + 1);
        printf("\n");
    }
    return 0;
}  