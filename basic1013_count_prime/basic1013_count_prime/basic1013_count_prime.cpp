
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int& num)
{
	int divide_num = 2;
	while (divide_num <= sqrt(num))
	{
		if (num%divide_num == 0)
			return false;
		divide_num++;
	}
	return true;
}

void getMtoNPrime(int& left_num, int& right_num, vector<int>& prime_nums)
{
	int count = 0;
	for (int i = 2;; i++)
	{
		if (isPrime(i))
		{
			count++;
			if (count <= right_num)
			{
				if (count >= left_num)
				{
					prime_nums.push_back(i);
				}
			}
			else
			{
				break;
			}
		}
	}

}

int main(int argc, char* argv[])
{
	int left_num, right_num;
	cin >> left_num >> right_num;
	vector<int> prime_nums;

	getMtoNPrime(left_num, right_num, prime_nums);
	
	int output_count = 0;
	for (auto iter = prime_nums.begin(); iter != prime_nums.end(); iter++)
	{
		output_count = iter - prime_nums.begin();
		cout << *iter;
		if (output_count % 10 == 9)
			cout << endl;
		else
		{
			if ((++iter) != prime_nums.end())
			{
				cout << ' ';
			}
			iter--;
		}
	}

	return 0;
}
