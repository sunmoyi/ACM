//
// Created by 孙启龙 on 2017/3/15.
//

#include<cstdio>
#include<algorithm>
using namespace std;
int A[100000], n;
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) 
            scanf("%d", &A[i]);
        int ans = A[0] - A[1];
        int MaxAi = A[0]; 
        for(int j = 1; j < n; j++) 
        { 
            ans = max(ans, MaxAi - A[j]);
            MaxAi = max(A[j], MaxAi); 
        }
        printf("%d\n", ans);
    }
    return 0;
}
