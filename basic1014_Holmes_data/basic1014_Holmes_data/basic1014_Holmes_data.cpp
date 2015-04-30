// basic1014_Holmes_data.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string DAY[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

bool isDayChar(char& ch)
{
	if ('A' < ch && ch <= 'Z')
		return true;
	else
		return false;
}

bool isHourChar(char& ch)
{
	if (('A' < ch && ch <= 'N') || ('0' < ch && ch <= '9'))
		return true;
	else
		return false;
}

bool isMinChar(char& ch)
{
	if (('A' < ch && ch <= 'Z') || ('a' < ch && ch <= 'z'))
		return true;
	else
		return false;
}


void getDayHour(vector<string>& str_vec, string& day, int& hour)
{
	int len = (str_vec[0].size() < str_vec[1].size()) ? str_vec[0].size() : str_vec[1].size();
	string& str1 = str_vec[0];
	string& str2 = str_vec[1];
	
	bool day_found_flag = false;

	for (int i = 0; i < len; i++)
	{
		if (!day_found_flag && isDayChar(str1[i]))
		{
			if (str1[i] == str2[i])
			{
				day_found_flag = true;
				day = DAY[str1[i]-'A'];
				continue;
			}
		}
		if (day_found_flag && isHourChar(str1[i]))
		{
			if (str1[i] == str2[i])
			{
				if (str1[i] > 'A') // must be an Alpha
				{
					hour = str1[i] - 'A' + 10;
				}
				else
				{
					hour = str1[i] - '0';
				}
				break;
			}
		}

	}

}


void getMin(vector<string>& str_vec, int& min)
{
	string& str1 = str_vec[2];
	string& str2 = str_vec[3];
	int len = (str1.size() < str2.size()) ? str1.size() : str2.size();
	for (int i = 0; i < len; i++)
	{
		if (isMinChar(str1[i]))
		{
			if (str1[i] == str2[i])
			{
				min = i;
			}
		}
	}


}

int main(int argc, char* argv[])
{
	vector<string> str_vec;
	str_vec.clear();
	string str_tmp;
	for (int i = 0; i < 4; i++)
	{
		cin >> str_tmp;
		str_vec.push_back(str_tmp);
	}
	string day;
	int hour, min;
	getDayHour(str_vec, day, hour);
	getMin(str_vec, min);
	cout << day << ' ';
	if (hour < 10)
		cout << '0';
	cout << hour << ':';
	if (min < 10)
		cout << '0';
	cout << min << endl;

	return 0;
}

