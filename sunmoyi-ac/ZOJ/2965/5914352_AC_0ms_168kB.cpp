#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t ;

    scanf("%d",&t);
    while(t--)
    {
         int n;
         scanf("%d",&n);
         if(n == 1)  printf("7\n");
         else if(n == 2) printf("27\n");
         else if(n >= 3 && n  <= 10)  printf("70\n");
         else if(n == 11)            printf("270\n");
         else                        printf("700\n");

    }
}
