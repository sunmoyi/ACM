//
// Created by 孙启龙 on 2016/12/25.
//


void BubbleSort(SqList &L)
{
    Exchange = 0;
    Compair = 0;
    int m = L.Length - 1, flag = 1;

    while((m > 0) && (flag == 1))
    {
        flag = 0;
        for(int j = 1; j <= m; j++)
        {
            Compair++;
            if(L.num[j] > L.num[j + 1])
            {
                flag = 1;
                swap(L.num[j], L.num[j + 1]);
                Exchange++;
            }
        }
        --m;
    }
}