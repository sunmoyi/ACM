//
// Created by 孙启龙 on 2016/11/3.
//

#include<stdio.h>
#include"myqueue.h"

int main (void)
{
    int cmd, e, status;
    queue Lady, Genman;
    initqueue(&Lady);
    initqueue(&Genman);
    printf("cmd: \n1.get a genman \n2.get a lady \n3. lenth of genman \n4. lenth of lady \n5.add genman \n6.add lady\n");
    while(scanf("%d", &cmd) != EOF)
    {
        switch(cmd) {
            case 1:
                status = Pop(&Genman, &e);
                if(status == -1)
                {
                    printf("out of Genman\n");
                    break;
                }
                printf("%d\n", e);
                break;
            case 2:
                status = Pop(&Lady, &e);
                if(status == -1)
                {
                    printf("out of Lady\n");
                    break;
                }
                printf("%d\n", e);
                break;
            case 3:
                printf("%d\n", Genman.size);
                break;
            case 4:
                printf("%d\n", Lady.size);
                break;
            case 5:
                scanf("%d\n", &e);
                Push(&Genman, e);
                break;
            case 6:
                scanf("%d\n", &e);
                Push(&Lady, e);
                break;
        }
    }
    return 0;
}
