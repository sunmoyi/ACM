//
// Created by 孙启龙 on 2016/12/9.
//

#define MOD 200
#define HashSize 200

Student HashStu[HashSize];

int  HashFunction(Student Stu)
{
    return (Stu.num) % MOD;
}

int FindHashSite(Student stu)
{
    int site = HashFunction(stu);
    while(HashStu[site].num != 0 && HashStu[site].num != stu.num)
        site++;
    return site;
}

void Insert(Student stu)
{
    int site = FindHashSite(stu);
    HashStu[site] = stu;
}

void init(Student Stu[], int Size)
{
    memset(HashStu, 0x0, sizeof(HashStu));
    for(int i = 0; i < Size; i++)
    {
        Insert(Stu[i]);
    }
    printf("Build over!");
}

void HashFind(Student stu)
{
    int site = FindHashSite(stu);
    if(HashStu[site].num == stu.num)
        printf("HashFind:  Found\n");
    else
        printf("HashFind:  Not Found.\n");
}


