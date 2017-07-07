#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
	string start, end;
	cin >> start;
	while (start == "START" && start != "ENDOFINPUT")
	{
		char a[1000];
		getchar();
		gets(a);
		getchar();
		cin >> end;
		int i;
		for (i = 0; i<strlen(a); i++)
		{
			if (a[i] >= 70 && a[i] <= 90)
				printf("%c", a[i] - 5);
			else if (a[i] >= 65 && a[i] <= 69)
				printf("%c", a[i] + 21);
			else
				cout << a[i];
		}
		cout << endl;
		cin >> start;
	}
	return 0;
}