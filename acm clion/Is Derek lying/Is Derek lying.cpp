//
// Created by 孙启龙 on 2017/7/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

#define abs(x)  (x) > 0 ? (x): (-(x))

using namespace std;
const int N=80004;

char xx[N],yy[N];
int main()
{
    int t,n,x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&x,&y);
        scanf("%s",xx);
        scanf("%s",yy);
        int ans=0;
        for(int i=0;i<n;i++){
            if(xx[i]==yy[i])ans++;
        }
        if(x+y<=(n+ans)&&abs(y-x)<=(n-ans)){
            printf("Not lying\n");
        }
        else printf("Lying\n");
    }
    return 0;
}