// basci1006_output_int_with_another_sytle.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char* argv[])
{
	int input_num;
	cin >> input_num;
	
	// GE 12...n
	vector<int> GE_output;
	int GE = input_num % 10;
	for (int i = 0; i < GE; i++)
	{
		GE_output.push_back(i + 1);
	}

	//SHI SS
	input_num /= 10;
	vector<char> SHI_output;
	int SHI = input_num % 10;
	for (int i = 0; i < SHI; i++)
	{
		SHI_output.push_back('S');
	}

	//BAI BB
	input_num /= 10;
	vector<char> BAI_output;
	int BAI = input_num % 10;
	for (int i = 0; i < BAI; i++)
	{
		BAI_output.push_back('B');
	}

	// output 
	for (auto iter = BAI_output.begin(); iter != BAI_output.end(); iter++)
	{
		cout << *iter;
	}
	for (auto iter = SHI_output.begin(); iter != SHI_output.end(); iter++)
	{
		cout << *iter;
	}
	for (auto iter = GE_output.begin(); iter != GE_output.end(); iter++)
	{
		cout << *iter;
	}
	cout << endl;
	
	
	return 0;
}

