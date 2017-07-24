//
// Created by 孙启龙 on 2016/12/9.
//

struct BSTree{
    Student node;
    BSTree *Lchild, *Rchild;
};
BSTree *root;

BSTree* Insert(Student St, BSTree *root)
{
    if(root == NULL)
    {
        root = (BSTree *)malloc(sizeof(BSTree));
        root->node = St;
        root->Rchild = root->Lchild = NULL;
    }
    else if (St.num > root->node.num)
        root->Rchild = Insert(St, root->Rchild);
    else
        root->Lchild = Insert(St, root->Lchild);
    return root;
}

void BuildBsTree(Student Stu[], int Size)
{
    root = (BSTree *)malloc(sizeof(BSTree));
    root->node = Stu[0];
    root->Lchild = root->Rchild = NULL;
    for(int i = 1; i < Size; i++)
    {
        Insert(Stu[i], root);
    }
}

void BSTreeFind(Student St, BSTree *root)
{
    if(root == NULL)
    {
        printf("BsTreeFind:           Not Found\n");
        return;
    }
    else if (root->node.num == St.num)
    {
        printf("BsTreeFind:           Found\n");
        return;
    }
    else if (root->node.num > St.num)
        BSTreeFind(St, root->Lchild);
    else
        BSTreeFind(St, root->Rchild);
}