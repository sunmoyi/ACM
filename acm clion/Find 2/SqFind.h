//
// Created by 孙启龙 on 2016/12/9.
//


int Sqfind(Student St, Student Stu[], int Size)
{
    for(int i = 0; i < Size; i++)
    {
        if(Stu[i].num == St.num)
        {
            printf("SqFind:               Found.\n");
            return 0;
        }
    }
    printf("SqFind:               Not Found,\n");
    return 0;
}