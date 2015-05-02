// basic1019_digital_black_hole.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;

void sortAndRevNum(int& num, int& rev_num)
{
	string s_num = to_string(num);
	int len = s_num.size();// do not use .size in the for cycle, because it will change after push_back
	for (int i = 0; i < 4 - len; i++)
	{
		s_num.push_back('0');
	}
	sort(s_num.begin(), s_num.end(), greater<int>());
	num = stoi(s_num);
	string reverse_num;
	reverse_num.clear();
	for (int i = s_num.size()-1; i>=0; i--)
	{
		reverse_num.push_back(s_num[i]);
	}
	rev_num = stoi(reverse_num);
}

int main(int argc, char* argv[])
{
	int num;
	cin >> num;

	if (num==6174)
		printf("7641 - 1467 = 6174\n");

	while (num != 0 && num != 6174)
	{
		int reverse_num;
		sortAndRevNum(num, reverse_num);
		printf("%04d - %04d = %04d\n", num, reverse_num, num-reverse_num);
		num = num - reverse_num;
	}
	
	return 0;
}

