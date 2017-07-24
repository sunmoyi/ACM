//
// Created by 孙启龙 on 2016/12/25.
//


int Partition(SqList &L, int low, int high)
{
    L.num[0] = L.num[low];
    int pivotkey = L.num[low];
    Compair++;
    while(low < high)
    {
        while(low < high && L.num[high] >= pivotkey)
        {
            Compair++;
            high--;
        }
        L.num[low] = L.num[high];
        Exchange++;
        while(low < high && L.num[low] <= pivotkey)
        {
            Compair++;
            ++low;
        }
        L.num[high] = L.num[low];
        Exchange++;
    }
    L.num[low] = L.num[0];
    return low;
}

void Qsort(SqList &L, int low, int high)
{
    if(low < high)
    {
        int pivotloc = Partition(L, low, high);
        Qsort(L, low, pivotloc);
        Qsort(L, pivotloc + 1, high);
    }
}

void QickSort(SqList &L)
{
    Compair = 0;
    Exchange = 0;
    Qsort(L, 1, L.Length);
}