#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

struct Student {
	char num[20];
	char name[20];
	char sex;
	float grade;
};

float average(Student * pstu, int &a)
{
	double num = 0;
	for (int i = 1; i <= 5; i++)
	{
		num += pstu[i].grade;
		if (pstu[i].grade < 60)
			a++;
	}
	return num / 5;
}

int main(void)
{
	Student student[6];
	for (int i = 1; i <= 5; i++)
	{
		cin >> student[i].num >> student[i].name >> student[i].sex >> student[i].grade;
	}

	int fail = 0;
	float aver = average(student, fail);
	printf("average: %f\tfail: %d\n", aver, fail);
	return 0;
}