//
// Created by 孙启龙 on 2017/2/12.
//

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char a[100005];
char b[100005];
int main()
{
    while(~scanf("%s%s",a,b))
    {
        if(strcmp(a,b)==0)printf("-1\n");
        else printf("%d\n",max(strlen(a),strlen(b)));
    }
}