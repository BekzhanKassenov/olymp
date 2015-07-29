#include <iostream>
#include <cstdio>

using namespace std;

bool check(int n)
{
	int a = n % 10;
	n /= 10;
	int b = n % 10;
	n /= 10;
	int c = n % 10;
	if (a != b && b != c && a != c)
		return true;
	return false; 
}

int main()
{
	for (int i = 100; i < 1000; i++)
		if (check(i))
			cout << i << endl;
	return 0;
}
