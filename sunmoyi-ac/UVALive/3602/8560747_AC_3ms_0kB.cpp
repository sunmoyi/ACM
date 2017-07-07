//
// Created by 孙启龙 on 2017/3/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxm 55
#define maxn 1010

using namespace std;

char str[maxm][maxn];

int main (void)
{
    int test, M, N;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &M, &N);
        for(int i = 0; i < M; i++)
            scanf("%s", str[i]);

        int cnt = 0, num_A, num_G, num_C, num_T, MAX;
        for(int i = 0; i < N; i++)
        {
            num_A = num_C = num_G = num_T = 0;
            for(int j = 0; j < M; j++)
            {
                switch(str[j][i])
                {
                    case 'A': num_A++;
                        break;
                    case 'C': num_C++;
                        break;
                    case 'G': num_G++;
                        break;
                    case 'T': num_T++;
                        break;
                    default:
                        ;
                }
            }
            MAX = max(max(max(num_A, num_C), num_G), num_T);
            cnt += M - MAX;
            if(MAX == num_A)
                printf("A");
            else if (MAX == num_C)
                printf("C");
            else if (MAX == num_G)
                printf("G");
            else
                printf("T");
        }
        printf("\n");
        printf("%d\n", cnt);
    }
    return 0;
}