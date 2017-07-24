//
// Created by 孙启龙 on 2016/12/25.
//

bool cmp(int aa, int bb)
{
    return aa > bb;
}

void Init(SqList &L, int Key)
{
    for(int i = 1; i <= RealSize; i++)
        L.num[i] = rand() % 100000;
    L.Length = RealSize;
    if(Key == 2)
        sort(L.num + 1, L.num + RealSize + 1);
    else if (Key == 3)
        sort(L.num + 1, L.num + RealSize + 1, cmp);
}

void DataCopy(SqList &L, SqList &S)
{
    memcpy(&S, &L, sizeof(SqList));
}

void OutPutSqlist(SqList &L)
{
    for(int i = 1; i <= RealSize; i++)
        printf("%d\t", L.num[i]);
    printf("\n\n");
}

void Sort(SqList &L)
{
    SqList now;
    memset(Exchange_Time, 0, sizeof(Exchange_Time));
    memset(Compair_Time, 0, sizeof(Compair_Time));
    printf("original SqList:\n");
    OutPutSqlist(L);

    DataCopy(L, now);
    BubbleSort(now);
    Exchange_Time[1] = Exchange;
    Compair_Time[1] = Compair;
    printf("after Bubble-sort:\n");
    OutPutSqlist(now);

    DataCopy(L, now);
    HeapSort(now);
    Exchange_Time[2] = Exchange;
    Compair_Time[2] = Compair;
    printf("after Heap-sort:\n");
    OutPutSqlist(now);

    DataCopy(L, now);
    InsertSort(now);
    Exchange_Time[3] = Exchange;
    Compair_Time[3] = Compair;
    printf("after Insert-sort:\n");
    OutPutSqlist(now);

    DataCopy(L, now);
    QickSort(now);
    Exchange_Time[4] = Exchange;
    Compair_Time[4] = Compair;
    printf("after Quick-sort:\n");
    OutPutSqlist(now);

    DataCopy(L, now);
    SelectSort(now);
    Exchange_Time[5] = Exchange;
    Compair_Time[5] = Compair;
    printf("after Select-sort:\n");
    OutPutSqlist(now);

    DataCopy(L, now);
    ShellSort(now);
    Exchange_Time[6] = Exchange;
    Compair_Time[6] = Compair;
    printf("after Shell-sort:\n");
    OutPutSqlist(now);
}

void SortInformation()
{
    printf("**********SortInformation**************\n");
    printf("sort\t\tExchange\t\tCompair\t\t\n");
    for(int i = 1; i <= 6; i++)
    {
        printf("%s\t\t %d\t\t %d\t\t\n", Sort_Name[i], Exchange_Time[i], Compair_Time[i]);
    }
}

int nemu(void)
{
    int cmd;
    printf("\n    *****************sort ******************\n");
    printf("    *%8c1---Random Data sort%11c\n",' ','*');
   // printf("    *%8c2---Increasing Data sort%7c\n",' ','*');
    //printf("    *%8c3---Decreasing Data sort%7c\n",' ','*');
    printf("    *%8c4---Compare shift Data Output%5c\n",' ','*');
    printf("    *%8c5---Quit%23c\n",' ','*');
    printf("    ****************************************\n");
    scanf("%d", &cmd);
    return cmd;
}