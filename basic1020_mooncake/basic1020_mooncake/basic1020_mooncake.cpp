// basic1020_mooncake.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

bool cmp(const vector<float>& left, const vector<float>& right)
{
	return left[1] >= right[1];
}

int main(int argc, char* argv[])
{
	int n, need;
	cin >> n >> need;
	vector< vector<float> > moon_cake;
	vector<float> one_cake, sum_cake, sum_price_cake;
	sum_cake.clear();
	sum_cake.resize(n);
	sum_price_cake.clear();
	sum_price_cake.resize(n);
	for (int i = 0; i < n; i++)
		cin >> sum_cake[i];
	for (int i = 0; i < n; i++)
		cin >> sum_price_cake[i];

	for (int i = 0; i < n; i++)
	{
		one_cake.clear();
		one_cake.push_back(sum_cake[i]);
		one_cake.push_back(sum_price_cake[i]/sum_cake[i]);
		moon_cake.push_back(one_cake);
	}

	sort(moon_cake.begin(), moon_cake.end(), cmp);

	float already_sum = 0;
	int index = 0;
	float sum_price = 0;
	while (index<moon_cake.size() && already_sum + moon_cake[index][0] < need )
	{
		already_sum += moon_cake[index][0];
		sum_price += moon_cake[index][0] * moon_cake[index][1];
		index++;
	}
	if (index < moon_cake.size())
	{
		sum_price += (need - already_sum) * moon_cake[index][1];
	}
	printf("%.2f\n",sum_price);

	return 0;
}

