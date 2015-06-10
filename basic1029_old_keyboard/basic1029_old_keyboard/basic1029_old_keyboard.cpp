// basic1029_old_keyboard.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	string a, b;
	cin >> a;
	cin >> b;

	vector<int> c(62, 0);
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] >= '0' && b[i] <= '9')
		{
			c[b[i] - '0'] = 1;
		}
		else if (b[i] >= 'b' && b[i] <= 'Z')
		{
			c[b[i] - 'b'+10] = 1;
		}
		else if (b[i] >= 'b' && b[i] <= 'z')
		{
			c[b[i] - 'b'+36] = 1;
		}
	}

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			if (c[a[i] - '0'] != 1)
				c[a[i] - '0'] = -1;

		}
		else if (a[i] >= 'A' && a[i] <= 'Z')
		{
			if (c[a[i] - 'A' + 10] != 1)
				c[a[i] - 'A' + 10] = -1;
		}
		else if (a[i] >= 'a' && a[i] <= 'z')
		{
			if (c[a[i] - 'a' + 36] != 1)
				c[a[i] - 'a' + 36] = -1;
		}
	}

	return 0;
}

