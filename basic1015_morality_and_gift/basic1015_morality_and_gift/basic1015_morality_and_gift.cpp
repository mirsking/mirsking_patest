// basic1015_morality_and_gift.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef vector< vector<int> > data_t;


bool sortSumDescend(const vector<int>& left_vec, const vector<int>& right_vec)
{
	//if (left_vec[3] > right_vec[3])
	//{
	//		return true;
	//}
	//else if (left_vec[3] == right_vec[3])
	//{
	//	if (left_vec[1] > right_vec[1])
	//	{
	//		return true;
	//	}
	//	else if (left_vec[1] == right_vec[1])
	//	{
	//		return left_vec[0] < right_vec[0];
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}
	//else
	//{
	//	return false;
	//}
	if (left_vec[3] != right_vec[3])
		return left_vec[3] > right_vec[3];
	else
	{
		if (left_vec[1] != right_vec[1])
			return left_vec[1] > right_vec[1];
		else
			return left_vec[0] < right_vec[0];
	}
}

inline void  output(data_t& vec)
{
	for (auto iter = vec.begin(); iter != vec.end(); iter++)
	{
		auto& tmp = *iter;
		printf("%d %d %d\n", tmp[0],tmp[1],tmp[2]);
	//	cout << tmp[0] << ' ' << tmp[1] << ' ' << tmp[2] << endl;
	}
}


int main(int argc, char* argv[])
{
	int num, low_score, high_score;
	//cin >> num >> low_score >> high_score;
	scanf("%d %d %d", &num, &low_score, &high_score);

	data_t m_g_data;
	data_t m_no_g_data;
	data_t no_m_no_g_data;
	data_t no_m_g_data;

	for (int i = 0; i < num; i++)
	{
		int id, morality, gift;
		scanf("%d %d %d",&id, &morality, &gift);
		//cin >> id >> morality >> gift;
		vector<int> line_data;
		
		if (morality>=low_score && gift >= low_score)
		{
			line_data.clear();
			line_data.push_back(id);
			line_data.push_back(morality);
			line_data.push_back(gift);
			line_data.push_back(morality + gift);

			if (morality >= high_score && gift >= high_score)
			{
				m_g_data.push_back(line_data);
			}
			else if (morality>=high_score)
			{
				m_no_g_data.push_back(line_data);
			}
			else if (morality >= gift)
			{
				no_m_no_g_data.push_back(line_data);
			}
			else
			{
				no_m_g_data.push_back(line_data);
			}
		}

	}
	sort(m_g_data.begin(), m_g_data.end(), sortSumDescend);
	sort(m_no_g_data.begin(), m_no_g_data.end(), sortSumDescend);
	sort(no_m_no_g_data.begin(), no_m_no_g_data.end(), sortSumDescend);
	sort(no_m_g_data.begin(), no_m_g_data.end(), sortSumDescend);

	cout << m_g_data.size() + m_no_g_data.size() + no_m_no_g_data.size() + no_m_g_data.size() << endl;
	output(m_g_data);
	output(m_no_g_data);
	output(no_m_no_g_data);
	output(no_m_g_data);
	
	return 0;
}

