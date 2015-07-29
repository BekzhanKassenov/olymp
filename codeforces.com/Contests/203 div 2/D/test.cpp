#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
	srand(time(NULL));
	int a[10];

	for (int i = 0; i < 10; i++)
		a[i] = rand() % 100;

	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';

	cout << endl; 

	for (int i = 0; i < 10; i++) {
		if (a[i] % 5 == 0)
			cout << a[i] << endl;
	}

	return 0;

}
