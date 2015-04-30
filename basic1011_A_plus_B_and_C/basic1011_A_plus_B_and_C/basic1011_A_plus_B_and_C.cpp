// basic1011_A_plus_B_and_C.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int case_num;
	cin >> case_num;
	long long A, B, C;
	for (int i = 0; i < case_num; i++)
	{
		cin >> A >> B >> C;
		cout << "Case #" << i+1 << ": ";
		cout << ((A + B>C) ? "true" : "false") << endl;
	}
	return 0;
}

