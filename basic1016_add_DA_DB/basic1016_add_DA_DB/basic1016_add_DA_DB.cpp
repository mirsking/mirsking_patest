// basic1016_add_DA_DB.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

long long findP(string& A, char& da)
{
	string tmp;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] == da)
		{
			tmp.push_back(da);
		}
	}
	if (tmp.size() == 0)
		return 0;
	else
		return stoll(tmp);
}

int main(int argc, char* argv[])
{
	string A, B;
	char da, db;
	cin >> A >> da >> B >> db;
	cout << findP(A, da) + findP(B, db) << endl;
	return 0;
}

