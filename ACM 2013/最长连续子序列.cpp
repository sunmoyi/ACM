#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

long maxSumRec(const vector<int>& a, int left, int right)
{
	if (left == right)
	{
		if (a[left] > 0)
			return a[left];
		else
			return 0;
	}

	int center = (left + right) / 2;
	long maxLeftSum = maxSumRec(a, left, center);
	long maxRightSum = maxSumRec(a, center + 1, right);

	//�������߶Ժ�һ�����ֽ�β���������ֵ 

	long maxLeftBorderSum = 0, leftBorderSum = 0;

	for (int i = center; i >= left; i--)
	{
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}

	//������ұ߶Ժ�һ�����ֽ�β���������ֵ 

	long maxRightBorderSum = 0, rightBorderSum = 0;

	for (int j = center + 1; j <= right; j++)
	{
		rightBorderSum += a[j];
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	return max3(maxLeftSum, maxRightSum,
		maxLeftBorderSum + maxRightBorderSum);
}


long maxSubSum3(const vector<int>& a)
{
	return maxSumRec(a, 0, a.size() - 1);
}

long max3(long a, long b, long c)
{
	if (a < b)
	{
		a = b;
	}
	if (a > c)
		return a;
	else
		return c;
}