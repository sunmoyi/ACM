//
// Created by 孙启龙 on 2017/3/8.
//

#include<cstring>  
#include<cstdio>  
#include<algorithm>  

using namespace std;

struct Contract {
    int v, id;
    bool operator < (const Contract& c) const {
        return v < c.v;
    }
};

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        const int maxn = 100000 + 10;

        Contract a[maxn];
        int b[maxn];

        long long sum = 0;
        int tmp;
        for(int i = 0; i < n; i ++) {
            scanf("%d", &tmp);
            a[i].id = i;
            a[i].v = tmp;
            sum += tmp;
        }
        memset(b, -1, sizeof(b));
        sort(a, a + n);

        if(sum%2) printf("No\n");
        else {
            sum /= 2;
            for(int i = n-1; i >= 0; i --) {
                if(sum >= a[i].v) {
                    sum -= a[i].v;
                    b[a[i].id] = 1;
                }
                else if(sum == 0) break;
            }
            printf("Yes\n");
            for(int i = 0; i < n; i ++) printf("%d%c", b[i], (i==n-1)?'\n':' ');
        }
    }
    return 0;
}  