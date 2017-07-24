#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>

using namespace std;

#include"Struct.h"
#include"AvlTreeFind.h"
#include"BlockFind.h"
#include"BSFind.h"
#include"HashFind.h"
#include "BsTreeFind.h"
#include"SqFind.h"

Student stu[MaxSize];
int size, times;
int a, b;

int main (void)
{
    /************************ input part *********************************/
    while(scanf("%d", &size) != EOF)
    {

        for(int i = 0; i < size; i++)
        {
            scanf("%d %d", &a, &b);
            stu[i].num = a, stu[i].age = b;
        };
        scanf("%d", &times);
        while(times--)
        {
            scanf("%d", &a);
            /************************* SqFind **************************************/
            Sqfind(Student(a, 0), stu, size);
            /************************* BSFind **************************************/
            BSFind(Student(a, 0), stu, size);
            /************************* HashFind ************************************/
            init(stu, size);
            HashFind(Student(a, 0));
            /************************* BSTree **************************************/
            BuildBsTree(stu, size);
            BSTreeFind(Student(a, 0), root);
            /************************* BlockFind ************************************/
            BlockBuild(stu, size);
            BlockFind(Student(a, 0), size);
            /************************* AVL-Tree Find ********************************/
            AVLBuild(stu, size);
            AVLsearch(Student(a, 0));
        }
    }
    return 0;
}