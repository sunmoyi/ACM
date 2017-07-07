#include<stdio.h>  
#include<string.h>  
#define MAX_LEN 1000  
char sz1[MAX_LEN];  
char sz2[MAX_LEN];  
int aMaxLen[MAX_LEN][MAX_LEN]; /*MaxLen(i, j)表示s1i 和s2j 的最长公共子序列的长度，那么递推关系如下*/  
int main()  
{  
    while(scanf("%s%s",sz1+1,sz2+1)>0)  
    {  
        int nLength1=strlen(sz1+1);  
        int nLength2=strlen(sz2+1);  
        int nTmp;  
        int i,j;  
        for(i=0;i<=nLength1;i++)  
           aMaxLen[i][0]=0;  
        for(j=0;j<=nLength1;j++)  
           aMaxLen[0][j]=0;  
        for(i=1;i<=nLength1;i++)  
        {  
            for(j=1;j<=nLength2;j++)  
            {  
                if(sz1[i]==sz2[j])  
                    aMaxLen[i][j]=aMaxLen[i-1][j-1]+1;  
                else  
                {  
                    if(aMaxLen[i][j-1]>aMaxLen[i-1][j])  
                        aMaxLen[i][j]=aMaxLen[i][j-1];  
                    else  
                        aMaxLen[i][j]=aMaxLen[i-1][j];  
                }  
            }  
        }  
        printf("%d\n",aMaxLen[nLength1][nLength2]);  
    }  
    return 0;  
}  