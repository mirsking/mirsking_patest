// basic1040_num_PAT.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

const int MM = 1000000007;

int main(int argc, char* argv[])
{
	string a;
	cin >> a;

	int num_p = 0;
	int num_pa = 0;
	int num_pat = 0;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == 'P')
			num_p++;
		else if (a[i] == 'A')
			num_pa = (num_pa + num_p) % MM;
		else if (a[i] == 'T')
			num_pat = (num_pat + num_pa) % MM;
	}

	cout << num_pat;

	return 0;
}

