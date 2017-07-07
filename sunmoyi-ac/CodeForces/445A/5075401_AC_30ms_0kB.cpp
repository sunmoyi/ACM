#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,i,j;
    char a[110][110],b[110][110];
    memset(a,'B',sizeof(a));
    for(i=0; i<100; i++)
        for(j=0; j<100; j++)
        {
            if(a[i][j]=='B'&&a[i][j+1]=='B'&&a[i+1][j]=='B')
            {
                a[i+1][j]='W';
                a[i][j+1]='W';
            }
            else if(a[i][j]=='B'&&a[i+1][j]=='B')a[i+1][j]='W';
            else if(a[i][j]=='B'&&a[i][j+1]=='B')a[i][j+1]='W';
        }
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0; i<n; i++)
            scanf("%s",b[i]);
        for(i=0; i<=n; i++)
            for(j=0; j<m; j++)
                if(b[i][j]=='.')
                    b[i][j]=a[i][j];
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
                printf("%c",b[i][j]);
            printf("\n");
        }
    }
    return 0;
}