#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

string A(int n) {
	string res;

	bool flag = 0;

	stringstream ss;

	for (int i = 0; i < n; i++) {
	 	ss << "sin(";
	 	ss << i + 1;
	 	
	 	if (i != n - 1)
	 		ss << (flag ? '+' : '-');
	 	
	 	flag ^= 1;
	}

	for (int i = 0; i < n; i++)
		ss << ')';

	return ss.str();	
}

string S(int n) {
	stringstream ss;

	for (int i = 1; i < n; i++)	
		ss << '(';

	for (int i = 1; i <= n; i++) {
		ss << A(i);
		ss << '+';
		ss << n - i + 1;

		if (i != n)
			ss << ')';
	}	

	return ss.str();
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	cout << S(n);

	return 0;
}
