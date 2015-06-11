// basic1037_cash.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;

const int A = 17;
const int B = 29;

int main(int argc, char* argv[])
{
	int a[3], b[3], c[3];

	scanf("%d.%d.%d %d.%d.%d", a, a + 1, a + 2, b, b + 1, b + 2);

	c[2] = b[2] - a[2];
	if (c[2] < 0)
	{
		c[2] += B;
		b[1] -= 1;
	}
	
	c[1] = b[1] - a[1];
	if (c[1] < 0)
	{
		c[1] += A;
		b[0] -= 1;
	}

	c[0] = b[0] - a[0];
	if (c[0] < 0)
	{
		c[0] += 1;
		c[1] = A - c[1] - 1;
		c[2] = B - c[2];
	}
	printf("%d.%d.%d", c[0], c[1], c[2]);

	return 0;
}

