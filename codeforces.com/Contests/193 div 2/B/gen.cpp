#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	freopen("in", "w", stdout);

	srand(time(NULL));

	int n = rand() % 10000 + 5;

	int k = rand() % (n / 2) + 1;

	cout << n << ' ' << k << endl;

	for (int i = 0; i < n; i++) 
		cout << rand() % 100000 + 1<< ' ';

	return 0;	
}
