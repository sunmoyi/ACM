#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

typedef struct Book {
    string name;
    string no;
    double price;
    Book *next = NULL;
}Book, *Linklist;

void Add(Linklist P)//插入书籍
{
    int n;
    Book *s, *q;
    q = P;
    cout << "请输入添加书的数目：" << endl;
    cin >> n;
    while (q->next)
        q = q->next;
    for (int i = 1; i <= n; i++)
    {
        s = new Book;
        cout << "Please input the name of the book:" << endl;
        cin >> s->name;
        cout << "Please input the ISBN of the book:" << endl;
        cin >> s->no;
        cout << "Please input the price of the book:" << endl;
        cin >> s->price;
        s->next = NULL;
        q->next = s;
        q = q->next;
    }
}

int main (void)
{
    Book list1;
    list1.next = NULL;
    Add(&list1);
}