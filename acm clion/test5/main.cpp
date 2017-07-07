#include <iostream>
#include <math.h>
#define MAXSIZE 20;
using namespace std;
typedef struct
{
    int Maxmark;//每个分组的最大值
    int start;//最大值对应的分组初始位置
}Index;
typedef struct
{
    int Snum;//关键字域，定为学号
    char Sname[10];
    int Sage;//学生年龄
    int Ssex;//学生性别
}Student;
typedef struct
{
    Student *R;//存储空间首地址
    int length;//当前长度
}SSTable;
int Search_Seq(SSTable ST,int num)
{
    //若找到，返回在表中的位置，否则为0
    ST.R[0].Snum=num;//哨兵
    cout<<"查找经历了:";
    int i;
    for( i=ST.length;ST.R[i].Snum!=num;--i)
        cout<<ST.R[i].Sname<<" ";//从后往前找
    return i;
}
int Search_Bin(SSTable ST,int num)
{
    //首先对关键字进行排序
    for(int i=0;i<ST.length;i++)
        for(int j=0;j<ST.length-i-1;i++){
            int temp;
            if(ST.R[j].Snum>ST.R[j+1].Snum){
                temp=ST.R[j].Snum;
                ST.R[j].Snum=ST.R[j+1].Snum;
                ST.R[j+1].Snum=temp;
            }
        }
    //若找到，返回在表中的位置，否则为0
    int low=1, high=ST.length;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(num==ST.R[mid].Snum) return mid;
        else if(num<=ST.R[mid].Snum) high=mid-1;
        else low=mid+1;
    }
    return 0;//表中不存在待查元素
}
//最大值函数
int getMax(int a[])
{
    int Max=a[0];
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]>Max) Max=a[i];
    }
    return Max;
}
int Search_Blo(SSTable ST,int num)
{
    int n=sqrt(ST.length);//平均分成n个小组
    //下面进行分块
    int i=0;
    int Num;
    for(int k=0;k<ST.length;k++){
        int j=k%n;
        Num[i][j]=ST.R[k].Snum;//学号转复制到二维数组
        if(j==n-1) i++;
    }
    //下面开始建立索引表
    Index id[n];
    for(int k=0;k<n;k++)
    {
        id[k].Maxmark=getMax(Num[k]);
        id[k].start=Num[k][0];
    }
    //进行查找
    int sloc;//寻找关键字的起始位置关键字
    for(int k=0;k<n-1;k++)
    {
        if(num>id[k].Maxmark&&num<=id[k+1].Maxmark)
            sloc=id[k+1].start;
    }
    int k;//把k这个变量弄到外面
    for(k=0;k<ST.length;k++)
    {
        if(ST.R[k].Snum==sloc)
            break;
    }
    for(;k<(k+n-1);k++){
        if(ST.R[k].Snum==num)
            break;
    }
    return k;
}

int main()
{
    cout << "----------【各种查找】----------" << endl;
    Student *R = new Student[MAXSIZE];
    SSTable s;
    s.length=0;
    cout << "请依次输入学生的学号，姓名，年龄，性别："<<endl;
    for(int i = 0;i < 16;i++){
        cin>>s.R[i].Snum>>s.R[i].Sname>>s.R[i].Sage>>s.R[i].Ssex;
        s.length++;
    }
    int op;
    int mynum;
    cout<<"请输入关键字（学生学号）：";
    cin>>mynum;
    cout<<"请选择要进行的查找方法（0.顺序查找  1.折半查找  2.索引表  3.二叉排序树  4.哈希表）：";
    cin>>op;
    int index;
    switch(op)
    {
        case 0:
            index=Search_Seq(s,mynum);
            cout<<"待查元素在下角标为"<<index<<"处"<<endl;
            break;
        case 1:
            index=Search_Bin(s,mynum);
            cout<<"待查元素在下角标为"<<index<<"处"<<endl;
            break;
        case 2:
            index=Search_Blo(s,mynum);
            cout<<"待查元素在下角标为"<<index<<"处"<<endl;
            break;

    }
    return 0;
}