// basic1033_old_keyboard_typing.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[])
{
	string a, b;
	//cin >> a;
	//cin >> b;
	char aa[100000], bb[100000];
	gets(aa);
	gets(bb);
	a = aa;
	b = bb;

	unordered_map<char, bool> key_map;
	for (int i = 0; i < a.size(); i++)
		key_map[a[i]] = true;

	for (int i = 0; i < b.size(); i++)
	{
		char tmp = b[i];
		if (b[i] >= 'a'&& b[i] <= 'z')
			tmp += ('A' - 'a');
		if (key_map.find(tmp) == key_map.end())
		{
			if (!(b[i] >= 'A' && b[i] <= 'Z'))
				cout << b[i];
			else
			{
				if (key_map.find('+') == key_map.end())
					cout << b[i];
			}
		}
	}
	cout << endl;
	return 0;
}

