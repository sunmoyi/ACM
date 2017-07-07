#include<cstdio>
using namespace std;

int main()
{
     int n , k;
     int t;
     scanf("%d",&t);
     int tt = 1;
     while(t--)
     {
           int  n , k;
           scanf("%d %d" , &n , &k);
           printf("Case #%d: %d %d" ,tt++ , 2*k, k);

           if(!k%2)
            {
              for(int i = 1;i <= n;i++)
              {
                   if(i == k  || i == 2*k)  continue;
                   printf(" %d" , i);
              }

            }

            else
            {
                 for(int i = 1;i <= k - 1;i++)
                        printf(" %d" , i);
                 for(int i = 2*k - 1;i >= k + 1;i--)
                        printf(" %d" , i);
                 for(int i = 2*k + 1;i <= n;i++)
                        printf(" %d" , i);

            }
            printf("\n");
     }
}
