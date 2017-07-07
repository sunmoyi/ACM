//
// Created by 孙启龙 on 2016/12/9.
//

#define MaxSize 100

typedef struct Student{
    int num;
    int age;
    Student(int num = 0, int age = 0): num(num), age(age){}
    bool friend operator < (const Student &a, const Student &b){
            return a.num < b.num;
    }
}Student, *PtrStudent;

Student student[MaxSize];