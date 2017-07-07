//
// Created by 孙启龙 on 2016/12/9.
//


void BSFind(Student St, Student Stu[], int Size)
{
    Student Stud[MaxSize];
    memcpy(Stud, Stu, MaxSize);
    sort(Stud, Stud + Size);

    int low = 0, high = Size;
    while(low <= high)
    {
        int mid = (low + high) >> 1;
        if(Stud[mid].num == St.num)
        {
            printf("BSFind:               Found\n");
            return ;
        }
        else if (Stud[mid].num > St.num)
            high = mid - 1;
        else
            low = mid + 1;
    }
    printf("BSFind:               Not Found\n");
}
