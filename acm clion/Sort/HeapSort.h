//
// Created by 孙启龙 on 2016/12/25.
//


void HeapAdjust(SqList &L, int n, int m)
{
    int rc = L.num[n];
    for(int j = 2 * n; j <= m; j++)
    {
        Compair++;
        if(j < m && L.num[j] < L.num[j + 1])
            j++;
        if(rc >= L.num[j])
            break;
        Exchange++;
        L.num[n] = L.num[j];
        n = j;
    }
    Exchange++;
    L.num[n] = rc;
}

void CreatHeap(SqList &L)
{
    int n = L.Length;
    for(int i = n / 2; i >= 1; i--)
    {
        HeapAdjust(L, i, n);
    }
}

void HeapSort(SqList &L)
{
    Compair = 0;
    Exchange = 0;

    CreatHeap(L);

    for(int i = L.Length; i > 1; i--)
    {
        int X = L.num[1];
        L.num[1] = L.num[i];
        L.num[i] = X;
        HeapAdjust(L, 1, i - 1);
    }
}