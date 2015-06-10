// basic_1027_print_hour_glass.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#define MAX_NUM 1000
#define ERROR_ROW -1

using namespace std;

void generateHourGlass(vector<int>& hour_glass, int max_num = MAX_NUM)
{
	hour_glass.clear();
	hour_glass.resize(max_num+1, ERROR_ROW);
	int i = 0, sum = 0;
	while (sum<=max_num)
	{
		sum = 2 * i*(i + 2) + 1;
		if (sum<=max_num)
			hour_glass[sum] = i;
		i++;
	}

}


void findHourGlassRow(const vector<int>& hour_glass, const int num, int& sum, int& row)
{
	sum =num;
	while (hour_glass[sum] == ERROR_ROW)
	{
		sum -= 1;
	}
	row = hour_glass[sum];
}

int main(int argc, char* argv[])
{
	vector<int> hour_glass;
	int num; char ch;
	cin >> num >> ch;
	generateHourGlass(hour_glass, num);

	int sum, row;
	findHourGlassRow(hour_glass, num, sum, row);

	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j < i; j++)
			printf(" ");
		for (int j = 0; j<2 * (row - i) + 1; j++)
			printf("%c", ch);
		//for (int j = 0; j < i; j++)
		//	printf(" ");
		printf("\n");
	}
	//printf("%c\n",ch);
	for (int i = row-1; i>=0; i--)
	{
		for (int j = 0; j < i; j++)
			printf(" ");
		for (int j = 0; j<2 * (row - i) + 1; j++)
			printf("%c", ch);
		//for (int j = 0; j < i; j++)
		//	printf(" ");
		printf("\n");
	}
	printf("%d",num-sum);

	return 0;
}

