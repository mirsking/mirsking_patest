// basic1003_I_want_to_pass.cpp : 定义控制台应用程序的入口点。
//

// 1 xPATx
// 2 xPAATxx
// 3 xPAAATxxx

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> findPAT(string& input_str)
{
	vector<int> return_vec;
	int i = 0;
	while (input_str[i] != 'P')
	{
		if (input_str[i] != 'A')
		{
			return return_vec; // if not begin with A or P, return NULL vector
		}
		else
		{
			i++; //count the A's num before P
		}
	}
	int P_pos = i;//  P's first pos

	while (input_str[i+1] != 'T')
	{
		if (input_str[i+1] != 'A')
		{
			return return_vec; // if between P and T is not A, return NULL vector
		}
		else
		{
			i++; //count the A's num between P and T
 		}
	}
	int T_pos = i+1; // T's first pos
	while (i+2 < input_str.size())
	{
		if (input_str[i+2] != 'A')
		{
			return return_vec; // if after T is not A, return NULL vector
		}
		else
		{
			i++; //count the A's num after T
		}
	}
	return_vec.push_back(P_pos);
	return_vec.push_back(T_pos);
	return_vec.push_back(input_str.size() - 1);
	return return_vec;

}


bool isYes(vector<int> pos)
{
	if (pos.size() != 3)
	{
		return false;
	}
	else
	{
		int after_A_num = pos[2] - pos[1];
		int between_A_num = pos[1] - pos[0]-1;// minius 1 is important
		int before_A_num = pos[0];
		if (before_A_num == 0)
		{
			if (after_A_num == 0 && between_A_num > 0) // PAT, PAAT, ...
				return true;
			else
				return false;
		}
		else
		{
			if (after_A_num%before_A_num != 0)
			{
				return false;
			}
			else
			{
				if (after_A_num / before_A_num != between_A_num) //xPATx, xPAATxx, ...
					return false;
				else
					return true;
			
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int count;
	string input_str;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> input_str;
		cout << ( isYes(findPAT(input_str))?"YES":"NO" ) << endl;
	}
	return 0;
}

