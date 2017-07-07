//
// Created by 孙启龙 on 2016/12/9.
//

#define MaxBlockNum 100
int block[MaxBlockNum];
int BlockSize, BlockNum;
Student *Stud;

void BlockBuild(Student Stu[], int Size)
{
    memset(block, 0, sizeof(block));
    BlockSize = (int)sqrt(Size), BlockNum = (int)sqrt(Size) + 1;
    Stud = (Student *)malloc(sizeof(Student) * MaxSize);
    memcpy(Stud, Stu, MaxSize);
    sort(Stud, Stud + Size);
    for(int i = 1; i <= BlockNum; i++)
    {
        block[i] = Stud[min(i * BlockSize, Size) - 1].num;
    }
    printf("block Build over.\n");
}

int FindBlock(Student stu)
{
    for(int i = 1; i <= BlockNum; i++)
    {
        if(block[i - 1] < stu.num && block[i] >= stu.num)
            return i;
    }
    return -1;
}

void BlockFind(Student stu, int Size)
{
    int site = FindBlock(stu);
    if(site == -1)
        printf("BlockFind:            Not Found.\n");
    for(int i = 0; i < BlockSize; i++)
    {
        if(Stud[(site - 1) * BlockSize + i].num == stu.num)
        {
            printf("BlockFind:            Found\n");
            return ;
        }
    }
    printf("BlockFind:            Not Found\n");
}