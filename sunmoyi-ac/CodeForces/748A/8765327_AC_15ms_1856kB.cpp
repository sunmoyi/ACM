#include<cstdio>
using namespace std;


int main()
{
     int lie , hang , pur;
     while(~scanf("%d%d%d" , &lie , &hang , &pur)){

         int ans_lie , ans_hang , flag;
        for(int i = 1;i <= lie;i++){
              int L = (i - 1)*hang*2 + 1;
              int R = i*hang*2;
              if(pur >= L && pur <= R) {
                    ans_lie = i;
                    ans_hang = (pur - L)/2 + 1;
                    if(pur%2) flag = 1;
                    else      flag = 0;
              }
        }
        char c;
        if(flag) c = 'L';
        else     c = 'R';
        printf("%d %d %c\n" , ans_lie , ans_hang , c);

     }
}