// basic1002_write_this_num.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
inline long long string_sum(string& str)
{
	long long return_int = 0;
	for (int i = 0; i < str.size(); i++)
	{
		return_int += str[i] - '0'; //convert ascii to num
	}
	return return_int;
}

string num_to_char[] = { "ling", "yi", "er", "san", "si", "wu",
					"liu", "qi", "ba", "jiu" };

vector<string> llongToStr(long long& input_num)
{
	vector<string> return_vec;
	do{
		return_vec.push_back(num_to_char[input_num % 10]);
		input_num = input_num / 10;
	} while (input_num > 0);
	return return_vec;
}

int main(int argc, char* argv[])
{
	string input_str;
	while (cin >> input_str)
	{
		long long num = string_sum(input_str);
		vector<string> pinyin_num = llongToStr(num);
		
		for (int i = pinyin_num.size(); i > 0;i--)
		{
			cout << pinyin_num[i - 1];
			if (i > 1) // last has no ' '
				cout << ' ';
		}
		cout << endl;
	}

	return 0;
}

