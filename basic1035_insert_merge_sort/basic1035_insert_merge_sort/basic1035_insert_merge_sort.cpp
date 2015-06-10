// basic1035_insert_merge_sort.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline bool compareVec(vector<int>& a, vector<int>& b)
{
	if (a.size() != b.size())
		return false;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

bool insertSort(vector<int>& a, vector<int>& b)
{
	bool right = false;

	for (int i = 1; i < a.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j]>a[i])
			{
				int tmp = a[i];
				for (int k = i-1; k >= j; k--)
				{
					a[k + 1] = a[k];
				}
				a[j] = tmp;
			}
		}

		if (right)
			return true;
		if (compareVec(a, b))
			right = true;
	}

	if (right)
		return true;	// last cycle
	else
		return false;
}

bool mergeSort(vector<int>& a, vector<int>& b)
{
	bool right = false;

	int left_min, left_max, right_min, right_max;
	int next;
	int length = a.size();
	vector<int> tmp;
	tmp.resize(length);

	for (int i = 1; i < length; i *= 2)
	{
		for (left_min = 0; left_min < length - i; left_min = right_max)
		{
			left_max = right_min = left_min + i;
			right_max = right_min + i;
			if (right_max > length)
				right_max = length;

			next = 0;
			while (left_min < left_max && right_min < right_max)
				tmp[next++] = a[left_min] < a[right_min] ? a[left_min++] : a[right_min++];

			while (left_min < left_max)
				a[--right_min] = a[--left_max];

			while (next>0)
				a[--right_min] = tmp[--next];
		}

		if (right)
			return true;
		if (compareVec(a, b))
			right = true;
	}

}


int main(int argc, char* argv[])
{

	int N;
	cin >> N;
	vector<int > a, b, a_bak;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
		a_bak.push_back(tmp);
	}

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}

	if (insertSort(a, b))
	{
		cout << "Insertion Sort" << endl;
		for (int i = 0; i < a.size(); i++)
		{
			cout << a[i];
			if (i + 1 < a.size())
				cout << ' ';
		}
	}
	else if (mergeSort(a_bak, b))
	{
		cout << "Merge Sort" << endl;
		for (int i = 0; i < a_bak.size(); i++)
		{
			cout << a_bak[i];
			if (i + 1 < a_bak.size())
				cout << ' ';
		}
	}
	
	return 0;
}

