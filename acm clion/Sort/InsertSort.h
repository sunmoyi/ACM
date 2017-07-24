//
// Created by 孙启龙 on 2016/12/25.
//


void InsertSort(SqList &L)
{
    Exchange = 0;
    Compair = 0;
    int i, j;
    for(i = 2; i <= L.Length; i++)
    {
        Compair++;
        if(L.num[i] < L.num[i - 1])
        {
            L.num[0] = L.num[i];
            L.num[i] = L.num[i - 1];
            for(j = i - 2; L.num[0] < L.num[j]; j--)
            {
                L.num[j + 1] = L.num[j];
                Compair++;
                Exchange++;
            }
            L.num[j + 1] = L.num[0];
        }
    }
}