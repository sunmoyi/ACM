#include <iostream>
#include <cstdio>

using namespace std;

int n,m;
char maze[110][110];

void Init()
{
    for(int i=1;i<=100;i++)
    {
        if(i%2)
        {
            for(int j=1;j<=100;j+=2)
            {
                maze[i][j] = 'B';
                maze[i][j+1] = 'W';
            }
        }
        else
        {
            for(int j=1;j<=100;j+=2)
            {
                maze[i][j] = 'W';
                maze[i][j+1] = 'B';
            }
        }
    }
}

int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        getchar();
        Init();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char a;
                scanf("%c",&a);
                if(a == '-')
                    maze[i][j] = '-';
            }
            getchar();
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                printf("%c",maze[i][j]);
            printf("\n");
        }
    }
    return 0;
}
