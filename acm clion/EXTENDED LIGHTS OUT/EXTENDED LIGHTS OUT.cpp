//
// Created by 孙启龙 on 2017/5/13.
//

#include <stdio.h>

int map[7][8], press[7][8];

int Test(void)
{
    int i, j;

    for (i=2; i<=5; i++)
    {
        for (j=1; j<=6; j++)
        {
            press[i][j] = (map[i-1][j]+press[i-1][j]+press[i-1][j-1]+press[i-1][j+1]+press[i-2][j])%2;
        }
    }

    for (j=1; j<=6; j++)
    {
        if ((press[5][j-1]+press[5][j]+press[5][j+1]+press[4][j])%2 != map[5][j])
           return 0;
    }
    return 1;
}

void Enum(void)
{
    int i;

    for (i=1; i<=6; i++)
       press[1][i] = 0;

    while (!Test())
    {
        press[1][1]++;
        i = 1;
        while (press[1][i] == 2)
        {
            press[1][i] = 0;
            i++;
            press[1][i]++;
        }
    }
}

int main()
{
    int T, t, i, j;

    scanf("%d", &T);
    for (t=1; t<=T; t++)
    {
        for (i=1; i<=5; i++)
            for (j=1; j<=6; j++)
                scanf("%d", &map[i][j]);
        Enum();
        printf("PUZZLE #%d\n", t);
        for (i=1; i<=5; i++)
        {
            for (j=1; j<6; j++)
                printf("%d ", press[i][j]);
            printf("%d\n", press[i][6]);
        }
    }
}