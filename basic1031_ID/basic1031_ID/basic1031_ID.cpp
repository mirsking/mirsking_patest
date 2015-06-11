// basic1031_ID.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


int weight[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
char M[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };

bool isIdIllegal(string& id)
{
	if (id.size() != 18)
		return false;

	int sum = 0;
	for (int i = 0; i < 17; i++)
	{
		if (id[i] >= '0'&&id[i] <= '9')
		{
			int num = id[i] - '0';
			sum += num*weight[i];
		}
		else
			return false;
	}

	int Z = sum % 11;

	if (id[17] == M[Z])
		return true;
	else
		return false;

}


int main(int argc, char* argv[])
{
	int N;
	cin >> N;
	vector< string > falseIDs;
	string id;
	for (int i = 0; i < N; i++)
	{
		cin >> id;
		if (!isIdIllegal(id))
		{
			falseIDs.push_back(id);
		}

	}

	if (falseIDs.size() == 0)
		printf("%s\n", "All passed");
	else
	{
		for (int i = 0; i < falseIDs.size(); i++)
		{
			printf("%s\n", falseIDs[i].c_str());
		}
	}
	return 0;
}

