#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

struct box_segment {
	int color;
	int len;
};

box_segment segments[200];
int score[200][200][200];

int click_box(int start, int end, int extra_len)
{
	int i, result, temp;
	if (score[start][end][extra_len] > 0)
		return score[start][end][extra_len];
	result = segments[end].len + extra_len;
	result *= result;
	if (start == end)
		return score[start][end][extra_len] = result;
	result += click_box(start, end - 1, 0);
	for (i = end - 1; i >= start; i--)
	{
		if (segments[i].color != segments[end].color)
			continue;
		temp = click_box(start, i, segments[end].len + extra_len) + click_box(i + 1, end - 1, 0);
		if (temp > result)
			//continue;
		result = temp;
		//break;
	}
	return score[start][end][extra_len] = result;
}

int main(void)
{
	int T, n, end, color;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		end = 0;
		cin >> segments[end].color;
		segments[end].len = 1;
		for (int j = 1; j < n; j++)
		{
			cin >> color;
			if (color == segments[end].color)
				segments[end].len++;
			else
			{
				end++;
				segments[end].color = color;
				segments[end].len = 1;
			}
		}
		memset(score, 0, sizeof(score));
		cout << "Case " << i + 1 << ": " << click_box(0, end, 0) << endl;
	}
}