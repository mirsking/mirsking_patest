// basic1032_wajueji.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[])
{
	unordered_map<int, long long> score_map;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		if (score_map.find(a) != score_map.end())
			score_map[a] += b;
		else
			score_map[a] = b;
	}

	int team = 1;
	long long score = 0;
	for (auto iter = score_map.begin(); iter != score_map.end(); iter++)
	{
		if (iter->second > score)
		{
			team = iter->first;
			score = iter->second;
		}
	}

	cout << team << ' ' << score;

	return 0;
}

