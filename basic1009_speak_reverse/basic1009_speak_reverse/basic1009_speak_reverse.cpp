// basic1009_speak_reverse.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <sstream>
#include <vector>


using namespace std;
int main(int argc, char* argv[])
{
	vector<string> str_vec;
	str_vec.clear();
	string str_tmp;
	while (cin >> str_tmp)
	{
		str_vec.push_back(str_tmp);
		printf("%X ", str_tmp);
	}

	for (auto iter = str_vec.rbegin(); iter != str_vec.rend(); iter++)
	{
		cout << *iter;
		if ((++iter) != str_vec.rend())
			cout << ' ';
		iter--;
	}
	return 0;
}

