#include<cstdio>
char st[4][4];
int main()
{
    for(int i = 0 ; i < 4 ; i++)
        scanf("%s",st[i]);
    int ok = 0;
    for(int i = 0 ; i < 4 ; i++)
        for(int j = 0 ; j < 4 ; j++){
            if(st[i][j] != 'o'){
                if(i > 0 && i < 3 && st[i - 1][j] == 'x' && st[i + 1][j] == 'x')
                    ok = 1;
                if(j > 0 && j < 3 && st[i][j - 1] == 'x' && st[i][j + 1] == 'x')
                    ok = 1;
                if(i > 0 && j > 0 && i < 3 && j < 3 && ((st[i - 1][j - 1] == 'x' && st[i + 1][j + 1] == 'x') || (st[i - 1][j + 1] == 'x' && st[i + 1][j - 1] == 'x')))
                    ok = 1;
                if(i < 2 && st[i + 1][j] == 'x' && st[i + 2][j] == 'x')
                    ok = 1;
                if(j < 2 && st[i][j + 1] == 'x' && st[i][j + 2] == 'x')
                    ok = 1;
                if(i > 1 && st[i - 1][j] == 'x' && st[i - 2][j] == 'x')
                    ok = 1;
                if(j > 1 && st[i][j - 1] == 'x' && st[i][j - 2] == 'x')
                    ok = 1;
                if(i > 1 && j > 1 && st[i - 1][j - 1] == 'x' && st[i - 2][j - 2] == 'x')
                    ok = 1;
                if(i < 2 && j < 2 && st[i + 1][j + 1] == 'x' && st[i + 2][j + 2] == 'x')
                    ok = 1;
                if(i > 1 && j < 2 && st[i - 1][j + 1] == 'x' && st[i - 2][j + 2] == 'x')
                    ok = 1;
                if(i < 2 && j > 1 && st[i + 1][j - 1] == 'x' && st[i + 2][j - 2] == 'x')
                    ok = 1;
            }
        }
    if(ok)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}