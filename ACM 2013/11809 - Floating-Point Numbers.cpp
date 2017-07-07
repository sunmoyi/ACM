#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	double M[20][40];
	long long E[20][40];

	// ���
	for (int i = 0; i <= 9; ++i)
		for (int j = 1; j <= 30; ++j)
		{
			double m = 1 - pow(2, -1 - i), e = pow(2, j) - 1;
			double t = log10(m) + e * log10(2);
			E[i][j] = t, M[i][j] = pow(10, t - E[i][j]);
		}

	// ���벢������
	string in;
	while (cin >> in && in != "0e0")
	{
		// ��������
		for (string::iterator i = in.begin(); i != in.end(); ++i) 
			if (*i == 'e') 
				*i = ' ';
		istringstream ss(in);
		double A; int B;
		ss >> A >> B;
		while (A < 1) A *= 10, B -= 1;
		// �ڴ�õı���Ѱ�Ҵ�
		for (int i = 0; i <= 9; ++i) for (int j = 1; j <= 30; ++j)
		{
			if (B == E[i][j] && (fabs(A - M[i][j]) < 1e-4 || fabs(A / 10 - M[i][j]) < 1e-4))
			{
				cout << i << ' ' << j << endl;
				break;
			}
		}
	}
}




/*
#include <cmath>
#include <cstdio>
#include <cstring>

double C[10][31];

void init() {
int i, j, v;
double f[10] = { 0.5 }, g[31], t;

for (i = 1, t = 0.5; i < 10; i++)
{
f[i] = f[i - 1] + t / 2;
t /= 2;
}
for (i = 0; i < 10; i++) f[i] = log10(f[i]);
for (i = 1, v = 2; i <= 30; i++)
{
g[i] = (v - 1.0)*log10(2.0);
v <<= 1;
}
for (i = 0; i < 10; i++) for (j = 1; j <= 30; j++)
C[i][j] = f[i] + g[j];
}

int main()
{
int i, j;
char s[100], *p;
double A, B;

init();

while (scanf("%s", s), strcmp(s, "0e0"))
{
p = strchr(s, 'e');
*p = 0;                 // ��'e'����λ�ñ�Ϊ'\0'
sscanf(s, "%lf", &A);
sscanf(p + 1, "%lf", &B);

int pi = 0, pj = 1;
B = A = log10(A) + B;   // ������A�洢���ʽֵ��B��¼��ֵ
for (i = 0; i < 10; i++)
for (j = 1; j <= 30; j++)
if (fabs(A - C[i][j]) < B)
pi = i, pj = j, B = fabs(A - C[i][j]);
printf("%d %d\n", pi, pj);
}
return 0;
}*/