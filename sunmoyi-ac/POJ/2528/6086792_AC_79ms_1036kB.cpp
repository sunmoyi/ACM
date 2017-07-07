#include <iostream>  
#include <cstring>  
#include <cstdio>  
#include <algorithm>  
using namespace std;  
  
#define M 10005  
  
int m, li[M], ri[M];  
int x[M<<3], col[M<<4], ans;  
bool hash[M];  
  
void PushDown(int rt) {  
     col[rt<<1] = col[rt<<1|1] = col[rt];  
     col[rt] = -1;  
}  
  
void Update(int L, int R, int c, int l, int r, int rt) {  
     if (l >= L && r <= R) {  
         col[rt] = c;  
         return;  
     }  
  
     if (col[rt] != -1) PushDown(rt);  
     int m = (l + r) >> 1;  
     if (m >= L) Update(L, R, c, l, m, rt<<1);  
     if (m < R)  Update(L, R, c, m+1, r, rt<<1|1);  
}  
  
void query(int l, int r, int rt) {  
    if (l == r) {  
        if (!hash[col[rt]]) {  
        ans++;  
        hash[col[rt]] = true;  
       }  
       return;  
    }  
    if (col[rt] != -1) PushDown(rt);  
    int m = (l + r) >> 1;  
    query(l, m, rt<<1);  
    query(m+1, r, rt<<1|1);  
}  
  
int BSearch(int ll, int hh, int xx) {  
    int mm;  
  
    while (ll <= hh) {  
        mm = (ll + hh) >> 1;  
        if (x[mm] == xx) return mm;  
        else if (x[mm] > xx)  hh = mm - 1;  
        else ll = mm + 1;  
    }  
    return -1;  
}  
  
int main()  
{  
    int t, n, i;  
  
    scanf ("%d", &t);  
    while (t--) {  
        memset(col, -1, sizeof (col));  
        memset (hash, false, sizeof (hash));  
        int nn = 0;  
        scanf ("%d", &n);  
        for (i = 1; i <= n; i++) {  
             scanf ("%d %d", &li[i], &ri[i]);  
             x[++nn] = li[i];  
             x[++nn] = ri[i];  
        }  
        sort(x+1, x+nn+1);  
        m = 1;  
        for (i = 2; i <= nn; i++) {  
             if (x[i] != x[i-1]) x[++m] = x[i];  
        }  
        for (i = m; i > 1; i--) {  
            if (x[i] - x[i-1] > 1) x[++m] = x[i] - 1;  
        }  
        sort(x+1, x+m+1);  
        for (i = 1; i <= n; i++) {  
            int l = BSearch(1, m, li[i]);  
            int r = BSearch(1, m, ri[i]);  
            Update(l, r, i, 1, m, 1);  
        }  
        ans = 0;  
        query(1, m, 1);  
        printf("%d\n", ans);  
    }  
    return 0;  
}  