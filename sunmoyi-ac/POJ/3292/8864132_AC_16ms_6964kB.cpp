//
// Created by 孙启龙 on 2017/4/21.
//

#include <iostream>
#include <vector>

using namespace std;

#define MAX_H 1000001 + 16
bool is_H_prime[MAX_H], is_H_semiprime[MAX_H];
int H_prime[MAX_H];
int accumulate[MAX_H];


int main(void)
{
	int p = 0;
	for (int i = 5; i < MAX_H; i += 4)
	{
		if (is_H_prime[i])
			continue;

		H_prime[p++] = i;
		for (int j = i * 5; j < MAX_H; j += i * 4)
			is_H_prime[j] = true;

	}
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			unsigned long long composite = H_prime[i] * H_prime[j];
			if (composite > MAX_H)
				break;
			is_H_semiprime[composite] = true;
		}
	}
	for (int i = 1; i < MAX_H; ++i)
		accumulate[i] = accumulate[i - 1] + is_H_semiprime[i];


	int h;
	while (cin >> h && h)
	{
		cout << h << ' ' << accumulate[h] << endl;
	}
}