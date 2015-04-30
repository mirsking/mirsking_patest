// Basic1004_score_rank.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <sstream>
#include <map>

using namespace std;
int main(int argc, char* argv[])
{
	map<int, string> score_rank_map;
	score_rank_map.clear();
	
	int student_num;
	cin >> student_num;


	string name, id;
	int score;
	for (int i = 0; i < student_num; i++)
	{
		cin >> name >> id >> score;
		score_rank_map[score] = name+' '+id;
	}

	auto iter = score_rank_map.end();
	iter--;
	cout << iter->second << endl;
	iter = score_rank_map.begin();
	cout << iter->second << endl;
	

	return 0;
}

