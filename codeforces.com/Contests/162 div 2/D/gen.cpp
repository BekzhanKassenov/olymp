#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n = 50000;

	printf("%d\n", n);

	for (int i = 0; i < n - 1; i++)
		printf("%d ", i + 1);

	printf("%d\n", n);
	return 0;
}
