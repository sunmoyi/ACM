#include <iostream>
using namespace std;

int main()
{
	char c;
	int sum = 0;

	while (c = getchar())
	{
		if (c == '\n')
		{
			cout << sum << endl;

			c = getchar();
			if (c == '0')
				break;
			else
				sum = c - '0';

			continue;
		}
		sum += c - '0';
		if (sum > 9)
		{
			sum = sum % 10 + sum / 10;
		}
	}
	return 0;
}