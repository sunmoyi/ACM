#include <stdio.h>  
int main(){  
    double a, b, c;  
    int z;  
    scanf("%d", &z);  
    while ( z-- ){  
        scanf("%lf%lf%lf", &a, &b, &c);  
        printf("%s\n", a+b>c && a+c>b && b+c>a ? "YES" : "NO");  
    }  
    return 0;  
}  