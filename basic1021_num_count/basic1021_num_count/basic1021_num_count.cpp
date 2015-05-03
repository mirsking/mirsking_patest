// basic1021_num_count.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	string num;
	cin >> num;
	vector<int> num_count;
	num_count.resize(10);
	for (int i = 0; i < num.size(); i++)
	{
		num_count[num[i] - '0'] += 1;
	}
	for (auto iter = num_count.begin(); iter != num_count.end(); iter++)
	{
		if (*iter != 0)
		{
			cout << iter - num_count.begin() << ':' << *iter << endl;
		}
	}
	return 0;
}

