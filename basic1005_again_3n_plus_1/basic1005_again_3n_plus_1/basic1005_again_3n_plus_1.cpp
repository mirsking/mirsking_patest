// basic1005_again_3n_plus_1.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;


inline int callatz(int input_num)
{
	if (input_num & 1)
		return ((3 * input_num) + 1) / 2;
	else
		return input_num / 2;
}

/**
* return all of 覆盖的数
*/
vector<int> isCallatz(int input_num)
{
	vector<int> return_vec;
	return_vec.clear();
	//return_vec.push_back(input_num);
	while (input_num != 1)
	{
		input_num = callatz(input_num);
		return_vec.push_back(input_num);
	}
	return return_vec;
}


bool isInCallatzVec(int num, vector<vector<int> >& callatz_vec)
{
	bool return_val = false;
	for (auto iter = callatz_vec.begin(); iter != callatz_vec.end(); iter++)
	{
		if (find(iter->begin(), iter->end(), num) != iter->end())
		{
			return_val = true;
			break;
		}
	}
	return return_val;
}

int main(int argc, char* argv[])
{
	int num;
	cin >> num;
	vector<int> input_nums;
	input_nums.clear();

	vector<vector<int> > callatz_vec;
	callatz_vec.clear();
	

	// test input, ignore the 
	int input_num;
	for (int i = 0; i < num; i++)
	{
		cin >> input_num;
		if (!isInCallatzVec(input_num, callatz_vec))
		{
			input_nums.push_back(input_num);
			callatz_vec.push_back( isCallatz(input_num) );
		}
	}
	
	//test the first ok nums
	auto iter = input_nums.begin();
	while (iter != input_nums.end())
	{
		if (isInCallatzVec(*iter, callatz_vec))
		{
			iter = input_nums.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	//sort by decrease and output
	sort(input_nums.begin(), input_nums.end(), greater<int>() );
	for (auto iter = input_nums.begin(); iter != input_nums.end(); iter++)
	{
		cout << *iter;
		if (iter != input_nums.end() - 1)
			cout << ' ';
	}
	cout << endl;


	return 0;
}

