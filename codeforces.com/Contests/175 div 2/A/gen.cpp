#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	freopen("in", "w", stdout);
	
	srand(time(NULL));

	int n = rand() % 10;

	int k = rand() % n;

	cout << n << ' ' << k << endl;
}
