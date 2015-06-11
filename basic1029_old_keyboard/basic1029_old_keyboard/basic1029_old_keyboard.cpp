// basic1029_old_keyboard.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <string>
#include <unordered_map>



using namespace std;

int main(int argc, char* argv[])
{
	string a, b;
	cin >> a;
	cin >> b;

	unordered_map<char, bool> key_map;

	for (int i = 0; i < b.size(); i++)
	{
		char tmp = b[i];
		if (b[i] >= 'a' && b[i] <= 'z')
			tmp += ('A'-'a');

		key_map[tmp] = true;
	}

	for (int i = 0; i < a.size(); i++)
	{
		char tmp = a[i];
		if (a[i] >= 'a' && a[i] <= 'z')
			tmp += ('A'-'a');
		if (key_map.find(tmp) == key_map.end())
		{
			cout << tmp;
			key_map[tmp] = true;
		}
	}

	return 0;
}

