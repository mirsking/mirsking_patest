// basic1008_array_right_cycle_move.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <list>

using namespace std;

int main(int argc, char* argv[])
{
	int array_size, move_count;
	cin >> array_size >> move_count;
	int real_move_count = move_count%array_size;
	list<int> num_array;
	int num_tmp;
	for (int i = 0; i < array_size-real_move_count; i++)
	{
		cin >> num_tmp;
		num_array.push_back(num_tmp);
	}
	auto iter = num_array.begin();
	for (int i = 0; i < real_move_count; i++)
	{
		cin >> num_tmp;
		iter = num_array.insert(iter, num_tmp);
		iter++;
	}

	for (auto iter = num_array.begin(); iter != num_array.end(); iter++)
	{
		cout << *iter;

		// space handle
		if ((++iter) != num_array.end())
			cout << ' ';
		iter--;
	}
	cout << endl;
	return 0;
}

