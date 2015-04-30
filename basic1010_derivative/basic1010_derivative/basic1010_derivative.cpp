// basic1010_derivative.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char* argv[])
{
	int coeff, index;
	vector<int> result_vec;
	while (cin >> coeff >> index)
	{
		int coeff_tmp = coeff*index;
		int index_tmp = index - 1;
		if (index != 0)
		{
			if (coeff_tmp != 0)
			{
				result_vec.push_back(coeff_tmp);
				result_vec.push_back(index_tmp);
			}
			else
			{
				result_vec.push_back(0);
				result_vec.push_back(0);
			}
		}
	}
	for (auto iter = result_vec.begin(); iter != result_vec.end(); iter++)
	{
		cout << *iter;
		if ((++iter) != result_vec.end())
			cout << ' ';
		iter--;
	}
	// only const input
	if (result_vec.size() == 0)
	{
		cout << 0 << ' ' << 0 << endl;
	}
	return 0;
}

