// basic1010_derivative.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char* argv[])
{
	int coeff, index;
	vector<long long> result_vec;
	while (cin >> coeff >> index)
	{
		long long coeff_tmp = coeff*index;
		int index_tmp = index - 1;
		if (index_tmp+1 != 0)
		{
			result_vec.push_back(coeff_tmp);
			result_vec.push_back(index_tmp);
		}
	}
	for (auto iter = result_vec.begin(); iter != result_vec.end(); iter++)
	{
		cout << *iter;
		if ((++iter) != result_vec.end())
			cout << ' ';
		iter--;
	}
	return 0;
}

