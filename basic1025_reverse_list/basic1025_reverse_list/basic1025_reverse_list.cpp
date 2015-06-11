// basic1025_reverse_list.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

struct list_node_t{
	int lid;
	int val;
	int rid;
};



int main(int argc, char* argv[])
{
	vector<list_node_t> list(100000), sorted_list, out_list;
	list_node_t list_node;
	int id, num, k;
	cin >> id >> num >> k;
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d %d", &list_node.lid, &list_node.val, &list_node.rid);
		list[list_node.lid] = list_node;
	}

	// sort the list
	while (id != -1)
	{
		sorted_list.push_back(list[id]);
		id = list[id].rid;
	}
	num = sorted_list.size();

	int last_node_index = k-1;
	while (last_node_index < num)
	{
		for (int i = last_node_index; i>last_node_index - k; i--)
		{
			out_list.push_back(sorted_list[i]);
		}
		last_node_index += k;
	}
	for (int i = last_node_index - k+1; i < num; i++)
	{
		out_list.push_back(sorted_list[i]);
	}


	// output
	for (auto iter = out_list.begin(); iter != out_list.end()-1; iter++)
	{
		iter->rid = (iter + 1)->lid;
		printf("%05d %d %05d\n", iter->lid, iter->val, iter->rid);
	}
	printf("%05d %d %d\n", out_list[num-1].lid, out_list[num-1].val, -1);

	return 0;
}

