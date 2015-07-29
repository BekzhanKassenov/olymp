#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	int a[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 22, 30, 41, 50, 61, 70, 81, 90, 111};

	if (n <= 20) {
		cout << a[n - 1] << endl;
		return 0;
	}

	int cnt = (n - 21) / 8 + 2;

	int c = (n - 21) % 8 + 2;

	cout << c;

	for (int i = 0; i < cnt; i++)
		cout << ((n % 2) ^ 1);

	return 0;	
}