// basic1001_3nplus1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

int callatz(int num)
{
	if (num & 1)//奇数
		return (3 * num + 1) / 2;
	else
		return num / 2;
}

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	static int call_count = 0;
	int input_num;
	while (cin >> input_num)
	{
		call_count = 0;
		while (input_num != 1)
		{
			input_num = callatz(input_num);
			call_count++;
		}
		cout << call_count << endl;
	}

	
	return 0;
}

