#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int get_code_from_char(char c) {
	if (isdigit(c))
		return (c - '0');

	return (c - 'A' + 10);	
}

char get_char_from_code(int n) {
	if (n <= 9)
		return n + '0';

	return (n - 10 + 'A');
}

struct big_int {
 	vector <int> arr;
 	int base;

 	big_int() {}

 	big_int(int base) : base(base) {}

 	big_int(const string& s, int base) : base(base) {
 		arr.resize(s.size());
 		for (size_t i = 0; i < s.size(); i++)
 			arr[i] = get_code_from_char(s[i]);

 		reverse(arr.begin(), arr.end());	
 	}

 	void operator /= (int n) {
 	    vector <int> res;

 		int flag = 0;

 		reverse(arr.begin(), arr.end());

 		for (size_t i = 0; i < arr.size(); i++) {
 			flag *= base;
 			flag += arr[i];
 			res.push_back(flag / n);
 			flag %= n;
 		}

 		reverse(res.begin(), res.end());

 		while (!res.empty() && res.back() == 0)
 			res.pop_back();

 		if (res.empty())
 			res.push_back(0);

 		arr = res;
 	}

 	int operator % (int n) const {
 		int res = 0;

 		for (int i = arr.size() - 1; i >= 0; i--)
 			res = (res * base + arr[i]) % n;

 		return res;	
 	}

 	void print() {
 	 	for (int i = arr.size() - 1; i >= 0; i--) 
 	 		cout << get_char_from_code(arr[i]);

 	 	cout << endl;	
 	}
};

bool ok(const big_int& a) {
	return (!a.arr.empty() && a.arr.back() != 0);
}

void move_to_system(big_int& a, int nbase) {
	big_int temp(nbase);

	while (ok(a)) {	
		temp.arr.push_back(a % nbase);
		a /= nbase;
	}

	a = temp;
	if (a.arr.empty())
		a.arr.push_back(0);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int base, nbase;
	string s;

	cin >> base >> nbase;
	cin >> s;

	big_int a(s, base);
	move_to_system(a, nbase);

	a.print();

	return 0;
}