// basci1036_coding_with_obama.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int N; 
	char a;
	cin >> N >> a;

	int row = (N+1) / 2;
	for (int i = 0; i < N; i++)
		printf("%c", a);
	printf("\n");

	for (int i = 0; i < row - 2; i++)
	{
		printf("%c", a);
		for (int j = 0; j < N - 2; j++)
			printf(" ");
		printf("%c\n", a);
	}


	for (int i = 0; i < N; i++)
		printf("%c", a);
	printf("\n");
	return 0;
}

