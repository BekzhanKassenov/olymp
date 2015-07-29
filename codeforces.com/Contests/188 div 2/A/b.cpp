#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	freopen("in", "r", stdin);
	long long n, k;

	cin >> n >> k;

	long long start = -1;

	for (int i = 0; i < k; i++)
		start += 2;

	cout << start;	
}