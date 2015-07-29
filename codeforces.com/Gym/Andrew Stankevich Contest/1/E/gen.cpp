#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	freopen("nice.in" ,"w", stdout);

	srand(time(NULL));

	cout << rand() % 15 + 1 << ' ' << rand() % 5 + 1 << ' ' << rand() + 13 << endl;

	return 0;
}
