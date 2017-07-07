//
// Created by 孙启龙 on 2016/10/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[1000000];
struct node{
    int star;
    int level;
}now;
int lian;
int date[] = {5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,3,3,3,3,3,2,2,2,2,2,2};
int drop[] = {5,5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,3,3,3,3,3,2};

void win()
{
    if(lian >= 2 && now.level >= 6)
        now.star += 2;
    else
        now.star++;
    if(now.star > date[now.level])
    {
        if(now.level == 0)
            return;
        now.level--;
        now.star -= date[now.level];
    }
    lian++;
    return;
}

void lost()
{
    lian = 0;
    if(now.level <= 20)
        now.star--;
    if(now.star < 0 && now.level < 20 && now.level >= 1)
    {
        now.level++;
        now.star = drop[now.level];
    }
    if(now.star < 0 && (now.level >= 20 || now.level == 0))
        now.star = 0;
    return;
}

int main (void)
{
    scanf("%s", str);
    lian = 0;
    now.level = 25, now.star = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == 'W')
            win();
        else
            lost();
    }
    if(now.level != 0)
        printf("%d\n", now.level);
    else
        printf("Legend\n");

    return 0;
}