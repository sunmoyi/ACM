#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;
const int N = 50;

class student
{
private:
	char name[11];
	char sex[11];
	char number[11];
	int score;
public:
	student()
	{
		strcpy_s(name, 10,"noname");
		strcpy_s(sex, 10,"nosex");
		strcpy_s(number, 10,"000");
		score = 0;
	}
	student(char *na, char *s, char *num, int sc)
	{
		strcpy_s(name, 10,na);
		strcpy_s(sex, 10,s);
		strcpy_s(number, 10,num);
		score = sc;
	}
	student(student &s)
	{
		strcpy_s(name, 10,s.name);
		strcpy_s(sex, 10, s.sex);
		strcpy_s(number, 10, s.number);
		score = s.score;
	}
	void input()
	{
		cin >> name >> sex >> number >> score;
	}
	void delete1(student stu[], int n)
	{
		student s2[N];
		int i, k;
		cout << "������Ҫɾ����ѧ��������" << endl;
		cin >> k;
		for (i = 0; i<n; i++)
		{
			if (i<k - 1)
			{
				s2[i] = stu[i];
			}
			if (i >= k - 1)
			{
				s2[i] = stu[i + 1];
			}

		}
		for (i = 0; i<n; i++)
		{
			s2[i].display1();
		}
	}
	void find(student stu[], int n)
	{
		student d;
		int i;
		char na[11];
		cout << "������Ҫ��ѧ����������" << endl;
		cin >> na;
		for (i = 0; i<n; i++)
		{
			if (strcmp(stu[i].name, na) == 0)
			{
				stu[i].display1();
			}
		}
	}
	void add(student stu[], int n)
	{
		student d, s1[N];
		int i, j, b;
		cout << "������Ҫ��ӵ�ѧ����Ϣ��" << endl;
		cin >> d.name >> d.sex >> d.number >> d.score;
		cout << "���뽫��ѧ����Ϣ�����ڼ��У�" << endl;
		cin >> b;
		for (i = 0, j = 0; i<n, j<n + 1; i++, j++)
		{
			if (i<b - 1)
			{
				s1[j] = stu[i];
				s1[j].display1();
			}
			if (i == b - 1)
			{
				strcpy_s(s1[j].name, 10, d.name);
				strcpy_s(s1[j].sex, 10, d.sex);
				strcpy_s(s1[j].number, 10, d.number);
				s1[j].score = d.score;
				s1[j].display1();
			}
			if (i>b - 1)
			{
				s1[j] = stu[i - 1];
				s1[j].display1();
			}
		}
	}
	void xiugai(student stu[], int n)
	{
		student c;
		int i, k;
		cout << "����Ҫ�޸ĵڼ���ѧ����Ϣ��" << endl;
		cin >> k;
		cout << "�������µ�ѧ����Ϣ��" << endl;
		cin >> c.name >> c.sex >> c.number >> c.score;
		for (i = 0; i<n; i++)
		{
			if (i == k - 1)
			{
				strcpy_s(stu[i].name, 10, c.name);
				strcpy_s(stu[i].sex, 10, c.sex);
				strcpy_s(stu[i].number, 10, c.number);
				stu[i].score = c.score;
			}
		}
		for (i = 0; i<n; i++)
		{
			stu[i].display1();
		}
	}


	void display1()
	{
		cout << "������" << name << "\t" << "�Ա�" << sex << "\t" << "ѧ�ţ�" << number << "\t" << "�ɼ���" << score << endl;
	}
	void display2(student stu[], int n)
	{
		int i;
		for (i = 0; i<n; i++)
		{
			cout << stu[i].name << "\t" << stu[i].sex << "\t" << stu[i].number << "\t" << stu[i].score << endl;
		}
	}
	void writetofile(student stu[], int n)
	{
		FILE *fp;
		int i;
		if ((fp = fopen("xuesheng.txt", "w")) == NULL)
		{
			cout << "��xuesheng.txtʧ��!" << endl;
			exit(0);
		}
		for (i = 0; i<n; i++)
		{
			fprintf(fp, "%s %s %s %d\n", stu[i].name, stu[i].sex, stu[i].number, stu[i].score);
		}
		fclose(fp);
	}
	void readfromfile(student stu[])
	{
		FILE *fp;
		int i;
		if ((fp = fopen("xuesheng.txt", "r")) == NULL)
		{
			cout << "��xuesheng.txtʧ�ܣ�" << endl;
			exit(0);
		}
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%s %s %s %d\n", stu[i].name, stu[i].sex, stu[i].number, &stu[i].score);
		}
		fclose(fp);
	}
};
void main()
{
	student s[N], a;
	int i, c, n;
	cout << "ѧ����Ϣ����ϵͳ" << endl;
	cout << "������ѧ��������" << endl;
	cin >> n;
	cout << "������ѧ����Ϣ��" << endl;
	for (i = 0; i<n; i++)
	{
		s[i].input();
	}
	getchar();
	a.writetofile(s, n);
	a.readfromfile(s);
	cout << "1��ɾ��" << endl;
	cout << "2������" << endl;
	cout << "3�����" << endl;
	cout << "4������" << endl;
	cout << "5���޸�" << endl;
	cin >> c;
	switch (c)
	{
	case 1: 
		a.delete1(s, n);
		break;
	case 2: 
		a.find(s, n);
		break;
	case 3: 
		a.display2(s, n);
		break;
	case 4: 
		a.add(s, n);
		break;
	case 5: 
		a.xiugai(s, n);
		break;
	}
}