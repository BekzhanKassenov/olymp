#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	freopen("input.txt", "w", stdout);

	cout << "400 400 108219" << endl;

	for (int i = 0; i < 400; i++) {
		for (int j = 0; j < 400; j++)
			cout << 'b';
		cout << endl;	
	}
	return 0;
}
