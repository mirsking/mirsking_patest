// basic1017_A_divide_B.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define CTOI(i) (i-'0')
#define ITOC(i) (i+'0')

void long_divide(const string& A, const int B, string& c, int&d)
{
	int yushu = 0, shang = 0;
	string a;
	for (int i = 0; i < A.size(); i++)
	{
		a.clear();
		a.push_back(ITOC(yushu));
		a.push_back(A[i]);
		
		yushu = stoi(a)%B;
		shang = stoi(a) / B;
		
		// inital 0  handle
		if (c.size() == 0 && shang == 0)
		{
			//do nothing
		}
		else
		{
			c.push_back(ITOC(shang));
		}
	}
	// c=0 handle
	if (c.size() == 0)
		c.push_back(ITOC(0));

	d = yushu;
}


int main(int argc, char* argv[])
{
	string A;
	int B;
	cin >> A >> B;
	string c;
	int d;
	long_divide(A,B,c,d);
	cout << c << ' ' << d;
	return 0;
}

