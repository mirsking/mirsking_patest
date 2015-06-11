// basic1023_smallest_num.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	vector<int> num;
	num.resize(10);
	//bool all_zero_flag=true;
	for (int i = 0; i < 10; i++)
	{
		cin >> num[i];
		//all_zero_flag &= (num[i] == 0);
	}
	if (num[0] != 0)
	{
		for (int i = 1; i < 10; i++)
		{
			if (num[i] != 0)
			{
				cout << i;
				num[i] -= 1;
				break;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < num[i]; j++)
			cout << i;
	}

	//if (all_zero_flag)
	//	cout << 0;

	cout << endl;

	return 0;
}

