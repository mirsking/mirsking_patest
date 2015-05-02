// basic1018_hammer_scissors.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	int count_array[9] = {0,0,0,0,0,0,0,0,0};
	int num;
	cin >> num;
	unordered_map<string, int > umap;
	umap["BB"] = 1;
	umap["BC"] = 0;
	umap["BJ"] = 2;
	umap["CB"] = 5;
	umap["CC"] = 4;
	umap["CJ"] = 3;
	umap["JB"] = 6;
	umap["JC"] = 8;
	umap["JJ"] = 7;
	string A, B;
	for (int i = 0; i < num;i++)
	{
		cin >> A >> B;
		count_array[umap[A + B]] += 1;
	}

	int w_count=0, l_count=0, t_count=0;
	for (int i = 0; i <=6; i += 3)
	{
		w_count += count_array[i];
		t_count += count_array[i + 1];
		l_count += count_array[i+2];
	}

	cout << w_count << ' ' << t_count << ' ' << l_count << endl;
	cout << l_count << ' ' << t_count << ' ' << w_count << endl;
	int b_win_count = count_array[0];
	int c_win_count = count_array[3];
	int j_win_count = count_array[6];
	 
	int max_count = max(b_win_count, max(c_win_count, j_win_count));
	if (max_count == b_win_count)
		cout << "B ";
	else if (max_count == c_win_count)
		cout << "C ";
	else
		cout << "J ";

	int b_lose_count = count_array[2];
	int c_lose_count = count_array[5];
	int j_lose_count = count_array[8];
	max_count = max(b_lose_count, max(c_lose_count, j_lose_count));
	if (max_count == c_lose_count)
		cout << "B";
	else if (max_count == j_lose_count)
		cout << "C";
	else
		cout << "J";

	cout << endl;
	return 0;
}

