#include <iostream>
#include <cstdio>

int get_num()
{
	char c;
	int res=0;
	bool flag = false;
	do
	{
		c = getchar();
		if (c == '-')
		flag = true;
	}
	while ( c < '0' || c > '9' );
	
	do
	{
		res=res*10+c-'0';
		c = getchar();
	}
	while ( c >= '0' && c <= '9' );
	
	if (flag)
		res *= -1;

	return res;
}
void pr_num2( int n )
{
	if ( n )
	{
		pr_num2( n / 10 );
		putchar( n % 10 + '0' );
	}
}
void pr_num( int n )
{
	if (n)
	{
		if (n < 0) {
			putchar('-');
			n *= -1;
		}

		pr_num2( n / 10 );
		putchar( n % 10 + '0' );
	}
	else
		putchar('0');
}

int main()
{
	int a = get_num(), b = get_num();

	if ((a & 1) != (b & 1) && a > 0 && b > 0) std :: swap(a, b);

	pr_num(a), putchar(' '),  pr_num(b);

	return 0;
}
