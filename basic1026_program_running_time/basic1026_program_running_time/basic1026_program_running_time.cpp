// basic1026_program_running_time.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
	const double CLK_TCK = 100.0;
	const int min = 60;
	const int hour = 60;
	long long a, b, c;
	cin >> a >> b;
	c = round( (b-a)/CLK_TCK );

	int ss = c%min;
	int mm = c / min;
	int hh = mm / hour;
	mm = mm %hour;

	printf("%02d:%02d:%02d\n", hh, mm, ss);
	
	return 0;
	
}

