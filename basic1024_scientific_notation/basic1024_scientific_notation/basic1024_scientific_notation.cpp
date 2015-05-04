// basic1024_scientific_notation.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[])
{
	string num;
	cin >> num;

	float NUM = stof(num);
	int point_off, c;
	auto iter = find(num.begin(), num.end(), 'E');
	if ( iter != num.end())
	{
		point_off = iter - num.begin() - 3; // 3 means + 1 .
		string tmp(iter+1, num.end());
		c = stoi(tmp);
	}
	else
	{
		point_off = num.end() - num.begin() - 3;
		c = 0;
	}

	point_off = point_off - c;
	if (point_off < 0)
		point_off = 0;

	printf("%.*f\n", point_off, NUM);
	
	return 0;
}

