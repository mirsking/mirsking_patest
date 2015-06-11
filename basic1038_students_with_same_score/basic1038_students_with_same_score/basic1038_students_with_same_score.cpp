// basic1038_students_with_same_score.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	int M, N;
	unordered_map<int, int> score_counts;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		if (score_counts.find(tmp) == score_counts.end())
			score_counts[tmp] = 1;
		else
			score_counts[tmp] += 1;
	}

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (score_counts.find(tmp) != score_counts.end())
			cout << score_counts[tmp];
		else
			cout << '0';

		if (i != N - 1)
			cout << ' ';
	}
	return 0;
}

