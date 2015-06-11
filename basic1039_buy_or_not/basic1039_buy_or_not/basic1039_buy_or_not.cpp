// basic1039_buy_or_not.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	unordered_map<char, int> has;
	string a, b;
	cin >> a;
	cin >> b;

	for (int i = 0; i < a.size(); i++)
	{
		if (has.find(a[i]) == has.end())
			has[a[i]] = 1;
		else
			has[a[i]] += 1;
	}

	int count = 0;

	for (int i = 0; i < b.size(); i++)
	{
		if (has.find(b[i]) != has.end())
		{
			if (has[b[i]]>0)
				has[b[i]] -= 1;
			else
				count += 1;
		}
		else
			count += 1;
	}

	if (count == 0)
		printf("Yes %d", a.size() - b.size());
	else
		printf("No %d", count);

	return 0;
}

