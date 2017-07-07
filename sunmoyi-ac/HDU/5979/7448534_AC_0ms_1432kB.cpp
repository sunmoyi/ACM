#include<cstdio>
#include<cmath>
using namespace std;
#define PI acos(-1.0)
int main()
{
    double r ;
    int   n;
    while(~scanf("%d %lf" , &n , &r))
    {
         double ans = 0;
          for(int i = 1;i <= n;i++)
          {
               double ang = 0;
               scanf("%lf" , &ang);
               ang  = ang/180.0 *PI;
               //printf("%lf %lf\n" , ang , sin(ang));
               ans += sin(ang);
              // printf("ans = %lf\n" , ans);
          }
          ans = ans*0.5*r*r;
          printf("%.3lf\n" , ans);
    }
}
