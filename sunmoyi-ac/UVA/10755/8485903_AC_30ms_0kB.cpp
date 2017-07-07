#include <stdio.h>  
#include <string.h>  
#define max(a, b) (a)>(b)?(a):(b)  
#define INF 0x3f3f3f3f3f3f3f  
const int N = 25;  
  
int t, A, B, C;  
long long g[N][N][N], sum[N][N][N][N], res[N][N][N][N];  
  
void init() {  
    scanf("%d%d%d", &A, &B, &C);  
    for (int i = 1; i <= A; i++)  
        for (int j = 1; j <= B; j++)  
            for (int k = 1; k <= C; k++)  
                scanf("%lld", &g[i][j][k]);  
}  
  
long long solve() {  
    long long ans = -INF;  
    for (int c = 1; c <= A; c++) {  
        for (int i = 1; i <= B; i++) {  
            for (int j = i; j <= B; j++) {  
                for (int k = 1; k <= C; k++) {  
                    long long h = 0;  
                    for (int l = k; l <= C; l++) {  
                        h += g[c][j][l];  
                        sum[i][j][k][l] = sum[i][j - 1][k][l] + h;  
                        if (c == 1) res[i][j][k][l] = sum[i][j][k][l];  
                        else res[i][j][k][l] = max(sum[i][j][k][l], res[i][j][k][l] + sum[i][j][k][l]);  
                        ans = max(ans, res[i][j][k][l]);  
                    }  
                }  
            }  
        }  
    }  
    return ans;  
}  
  
int main() {  
    scanf("%d", &t);  
    while (t--) {  
        init();  
        printf("%lld\n", solve());  
        if (t) printf("\n");  
    }  
    return 0;  
}  