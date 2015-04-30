// basic1007_prime_number_pair.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long long& num)
{
	int divide_num=2;
	while (divide_num <= sqrt(num))
	{
		if (num%divide_num == 0)
			return false;
		divide_num++;
	}
	return true;
}

void getPrime(long long& max_num, vector<long long>& return_vec)
{
	// for this problem, assume n>1, so we begin from 3
	for (long long i = 3; i <= max_num; i++)
	{
		if (isPrime(i))
			return_vec.push_back(i);
	}
} 

inline bool isPrimePair(long long& left_int, long long& right_int)
{
	if ((right_int - left_int) ==2) // 
	{
		return true;
	}
	else
	{
		return false;
	}

}

int main(int argc, char* argv[])
{
	long long input_num;
	cin >> input_num;
	vector<long long> prime_nums;
	getPrime(input_num, prime_nums);

	int prime_pair_count = 0;
	for (auto iter = prime_nums.begin(); iter != prime_nums.end(); iter++)
	{
		if ((iter + 1) != prime_nums.end())
		{
			if (isPrimePair(*iter, *(iter + 1)))
			{
				prime_pair_count++;
			}
		}
	}

	cout << prime_pair_count << endl;
	
	return 0;
}

