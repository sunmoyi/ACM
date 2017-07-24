//
// Created by 孙启龙 on 2016/12/25.
//

void ShellSort(SqList &L, int dk)
{
    for(int i = dk + 1; i <= L.Length; i++)
    {
        Compair++;
        if(L.num[i] < L.num[i - dk])
        {
            L.num[0] = L.num[i];
            int j;
            for(j = i - dk; j > 0 && L.num[j] > L.num[0]; j -= dk)
            {
                L.num[j + dk] = L.num[j];
                Exchange++;
            }
            L.num[j + dk] = L.num[0];
        }
    }
}

void ShellSort(SqList &L)
{
    Compair = 0;
    Exchange = 0;
    int t = 6, dt[7] = {0, 23, 17, 13, 7, 5, 1};
    for(int k = 1; k <= t; k++)
    {
        ShellSort(L, dt[k]);
    }
}