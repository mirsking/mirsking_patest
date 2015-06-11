// basic1034_operation.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;


inline void printFrac(long long a1, long long a2)
{
	long long k = a1 / a2;
	if (k < 0)
	{
		if (a1%a2 != 0)
			printf("(%lld %lld/%lld)", k, abs(a1%a2), a2);
		else
			printf("(%lld)", k);
	}
	else if (k>0)
	{
		if (a1%a2 != 0)
			printf("%lld %lld/%lld", k, a1%a2, a2);
		else
			printf("%lld", k);
	}
	else if (k == 0)
	{
		if (a1 > 0)
			printf("%lld/%lld", a1, a2);
		else if (a1<0)
			printf("(%lld/%lld)", a1, a2);
		else
			printf("0");
	}
}

inline void printRes(long long a1, long long a2, long long b1, long long b2, long long c1, long long c2, char ope)
{
	printFrac(a1, a2);
	printf(" %c ",ope);
	printFrac(b1, b2);
	printf(" = ");
	printFrac(c1, c2);
	printf("\n");
}

inline long long maxYUE(long long a, long long b)
{
	long long tmp;
	a = abs(a);
	b = abs(b);
	while (a%b)
	{
		tmp = b;
		b = a%b;
		a = tmp;
	}
	return b;
}

void myPlus(long long a1, long long a2, long long b1, long long b2, long long& c1, long long& c2)
{
	c1 = a1*b2 + a2*b1;
	c2 = a2*b2;
	if (c1 != 0)
	{
		long long tmp = maxYUE(c1, c2);
		c1 = c1 / tmp;
		c2 = c2 / tmp;
	}
}

void myMinus(long long a1, long long a2, long long b1, long long b2, long long& c1, long long& c2)
{
	c1 = a1*b2 - a2*b1;
	c2 = a2*b2;
	if (c1 != 0)
	{
		long long tmp = maxYUE(c1, c2);
		c1 = c1 / tmp;
		c2 = c2 / tmp;
	}
}

void myTimes(long long a1, long long a2, long long b1, long long b2, long long& c1, long long& c2)
{
	c1 = a1*b1;
	c2 = a2*b2;
	if (c1 != 0)
	{
		long long tmp = maxYUE(c1, c2);
		c1 = c1 / tmp;
		c2 = c2 / tmp;
	}
}

bool myDivide(long long a1, long long a2, long long b1, long long b2, long long& c1, long long& c2)
{
	if (b1 == 0)
		return false;
	else
	{
		if (b1 < 0)
		{
			b1 = -b1;
			b2 = -b2;
		}
		myTimes(a1, a2, b2, b1, c1, c2);
		return true;
	}
}


int main(int argc, char* argv[])
{
	long long a1, a2, b1, b2;
	long long c1, c2;
	scanf("%lld/%lld %lld/%lld",&a1, &a2, &b1, &b2);

	if (a1 != 0)
	{
		long long tmp = maxYUE(a1, a2);
		a1 = a1/tmp;
		a2 = a2 / tmp;
	}
	if (b1 != 0)
	{
		long long tmp = maxYUE(b1, b2);
		b1 = b1/tmp;
		b2 = b2 / tmp;
	}


	myPlus(a1, a2, b1, b2, c1, c2);
	printRes(a1, a2, b1, b2, c1, c2, '+');

	myMinus(a1, a2, b1, b2, c1, c2);
	printRes(a1, a2, b1, b2, c1, c2, '-');

	myTimes(a1, a2, b1, b2, c1, c2);
	printRes(a1, a2, b1, b2, c1, c2, '*');

	if (myDivide(a1, a2, b1, b2, c1, c2))
		printRes(a1, a2, b1, b2, c1, c2, '/');
	else
	{
		printFrac(a1, a2);
		printf(" / ");
		printFrac(b1, b2);
		printf(" = Inf\n");
	}
	return 0;
}

