// basic1012_number_classify.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;

void classify(const int key, vector<int>& nums, vector<vector<int> >& classified_nums)
{
	classified_nums.resize(key);
	for (auto& num : nums)
	{
		for (int i = 0; i < key; i++)
		{
			if (num%key == i)
			{
				classified_nums[i].push_back(num);
				break;
			}
		}
	}

}

int A1(vector<int>& nums)
{
	int return_val=0;
	if (nums.size() == 0)
	{
		return_val = -1; //-1 means output N
	}
	else
	{
		int even_num_count = 0;
		for (auto& num : nums)
		{
			if (num % 2 == 0)
			{
				return_val += num;
				even_num_count++;
			}
		}
		if (even_num_count == 0)
		{
			return_val = -1;
		}
	}
	return return_val;
}


int A2(vector<int>& nums)
{
	int return_val=0;
	if (nums.size() == 0)
	{
		return_val = -1; //-1 means output N
	}
	else
	{
		int index = 0;
		for (auto& num : nums)
		{
			if (index %2 == 0) // even num
			{
				return_val += num;
			}
			else
			{
				return_val -= num;
			}
			index++;
		}
	}
	return return_val;
}

inline int A3(vector<int>& nums)
{
	int return_val = 0;
	if (nums.size() == 0)
	{
		return_val = -1;
	}
	else
	{
		return_val = nums.size();
	}
	return return_val;
}


float A4(vector<int>& nums)
{
	float return_val = 0;
	if (nums.size() == 0)
	{
		return_val = -1; //-1 means output N
	}
	else
	{
		for (auto& num : nums)
		{
			return_val += num;
		}
		return_val = static_cast<float>(return_val / nums.size());
	}
	return return_val;
}

int A5(vector<int>& nums)
{
	int return_val;
	if (nums.size() == 0)
	{
		return_val = -1;
	}
	else
	{
		sort(nums.begin(), nums.end(), greater<int>());
		return_val = nums[0];
	}
	
	return return_val;

}
inline void mk_print(int result_int, bool has_space=true)
{
	if (result_int != -1)
		cout << result_int;
	else
		cout << 'N';
	if (has_space)
		cout << ' ';
}
inline void mk_print(float result_float, bool has_space=true)
{
	if (abs(result_float + 1) < 10e-5)
		cout << 'N';
	else
		printf("%.1f", result_float);
	if (has_space)
		cout << ' ';
}

int main(int argc, char* argv[])
{
	int input_num;
	cin >> input_num;
	vector<int> nums;
	int input_tmp;

	for (int i = 0; i < input_num; i++)
	{
		cin >> input_tmp;
		nums.push_back(input_tmp);
	}
	vector<vector<int> > classified_nums;
	int key = 5;
	classify(key, nums, classified_nums);
	
	mk_print(A1(classified_nums[0]));
	mk_print(A2(classified_nums[1]));
	mk_print(A3(classified_nums[2]));
	mk_print(A4(classified_nums[3]));
	mk_print(A5(classified_nums[4]),false);
	
	return 0;
}

