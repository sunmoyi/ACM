//
// Created by 孙启龙 on 2017/4/27.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int prim[1230]={2,3};
int
countt=0;

void prime(void)
{

    int tally=2;
    int i,j,flag;
    for(i=5;i<10000;i+=2)
    {
        for(j=0,flag=1;prim[j]*prim[j]<=i;j++)
            if(i%prim[j]==0)flag=0;
        if(flag)
        {
            prim[tally]=i;
            tally++;
        }
    }
    return;
}

void minu(int num,int i)
{
    if(i<0)
        return;
    if(num-prim[i]==0)
        countt++;
    else if(num-prim[i]>0)
        minu(num-prim[i],i-1);
    else
        return;
    return;
}

int main(void)
{
    prime();
    int num,i,k;
    for(;;)
    {
        cin >> num;
        if(num==0)
            return 0;
        for(i=0;i<1230;i++)
            if(num==prim[i])
            {
                countt++;
                k=i-1;
                break;
            }
            else if(num<prim[i])
            {
                k=i-1;
                break;
            }
        for(i=k;i>=0;i--)
            minu(num,i);
        cout<< countt<<endl;
        countt=0;
    }
    return 0;
}