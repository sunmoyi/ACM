#include<cstdio>
#include<cmath>
using namespace std;

typedef long long LL;
LL gcd(LL a, LL b) {
  return b == 0 ? a : gcd(b, a%b);
}

int main()
{
  LL a  ,b;
  while(~scanf("%lld%lld" , &a , &b))
  {
       int flag = 1;
       LL G = gcd(a , b);
       LL temp = a*a - 4*G*b;
       if(temp < 0)                             {flag = 0;}
       else if((LL)sqrt(temp) * (LL)sqrt(temp) != temp) {flag = 0;}
       else if(((LL)sqrt(temp) + a)%2)          {flag = 0;}

       if(!flag)  printf("No Solution\n");
       else
       {
           LL x = ((LL)sqrt(temp) + a)/2;
           LL y = a - x;

            printf("%lld %lld\n" , y , x);
       }
  }
}

