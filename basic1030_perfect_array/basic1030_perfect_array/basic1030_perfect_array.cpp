// basic1030_perfect_array.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	int N;
	long long p;
	vector<long long> lis;
	cin >> N >> p;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		lis.push_back(tmp);
	}

	sort(lis.begin(), lis.end());

	int count = 1;

	for (int i=0; i < N; i++)
	{
		for (int j = i + count - 1; j < N; j++)
		{
			if (lis[j] <= lis[i] * p)
			{
				if (j - i + 1 > count)
					count = j - i + 1;
			}
			else
				break;
		}
	}
	
	cout << count;

	return 0;
}

