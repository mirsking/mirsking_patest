// basic1022_A_plus_B_with_D.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	int sum = a + b;
	int shang = 0, yushu = 0;
	vector<int> result;
	while (sum>=c)
	{
		result.push_back(sum%c);
		sum = sum / c;
	}
	result.push_back(sum);

	for (auto iter = result.end(); iter != result.begin(); iter--)
	{
		cout << *(iter - 1);
	}
	cout << endl;

	return 0;
}

