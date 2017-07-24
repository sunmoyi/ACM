//
// Created by 孙启龙 on 2016/12/25.
//


void SelectSort(SqList &L)
{
    for(int i = 1; i < L.Length; i++)
    {
        int k = i;
        for(int j = i + 1; j <= L.Length; j++)
        {
            Compair++;
            if(L.num[j] < L.num[k])
                k = j;
        }
        if(k != i)
        {
            Exchange++;
            swap(L.num[i], L.num[k]);
        }
    }
}