#include<cstdio>
#include<cstring>
#include<algorithm>
#include<random>

#define MaxSize 1000
#define RealSize 50
using namespace std;

struct SqList{
    int num[MaxSize];
    int Length;
}root;
char Sort_Name[10][15] = {"", "BubbleSort", "HeapSort", "InsertSort", "QuickSort", "SelectSort", "ShellSort"};
int Compair_Time[10];
int Exchange_Time[10];
int Compair;
int Exchange;

#include"BubbleSort.h"
#include"HeapSort.h"
#include"InsertSort.h"
#include"QickSort.h"
#include"SelectSort.h"
#include"ShellSort.h"
#include"option.h"

int main (void)
{
    int cmd;
    while(cmd = nemu())
    {
        switch (cmd)
        {
            case 1:
                Init(root, 1);
                Sort(root);
                break;
            //case 2:
              //  Init(root, 2);
                //Sort(root);
                //break;
            //case 3:
              //  Init(root, 3);
                //Sort(root);
                //break;
            case 4:
                SortInformation();
                break;
            default:
                return 0;
        }
    }
}