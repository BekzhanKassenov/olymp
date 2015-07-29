#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int a[101], n, k, i, j, cnt;

int read()
{
	char c;

	int ans = 0;

	do
		{
			c = getchar();
		}

	while (c < '0' || c > '9');

	do
		{
			ans = ans * 10 + c - '0';
			c = getchar();
		}	
	while (c >= '0' && c <= '9');

	return ans;	
}

void write(int n, int gl = 0)
{
	if (n)
		{
			write(n / 10, gl + 1);
			putchar(n % 10 + '0');
		}
	else
		{
			if (gl == 0)
				{
					putchar(' ');
					putchar(' ');
					putchar(' ');
					putchar('0');
				}
			else	
				for (; gl < 4; gl++)
					putchar(' ');
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	n = read(), k = read();

	for (i = 0; i < n; i++)
		a[i] = read();

	cnt = n / k + (n % k != 0);

	for (i = 0; i < cnt && i < n; i++)
		{
			for (j = i; j < n; j += cnt)
			    write(a[j]);
				
			putchar('\n');
		}
  	return 0;
}
