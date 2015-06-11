#include <iostream>
#include <sstream>
using namespace std;

const string MIN_DATA = "1814/09/06";
const string MAX_DATA = "2014/09/06";

int main(int argc, char** argv)
{
	int N;
	int count = 0;
	string name, data;
	string min_name, max_name;
	string min_age, max_age;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> name >> data;
		if (data.compare(MIN_DATA) >= 0 && data.compare(MAX_DATA) <= 0)
		{
			if (count == 0)
			{
				min_age = data;
				min_name = name;
				max_age = data;
				max_name = name;
			}
			count++;
			if (data.compare(min_age) > 0)
			{
				min_age = data;
				min_name = name;
			}
			if (data.compare(max_age) < 0)
			{
				max_age = data;
				max_name = name;
			}
		}
	}

	if (count > 0)
		printf("%d %s %s", count, max_name.c_str(), min_name.c_str());
	else
		cout << '0' << endl;

	return 0;
}