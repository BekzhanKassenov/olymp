#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct big_int {
 	vector <int> arr;
 	int base;

 	big_int() : base(10) {}

 	big_int(const string& s) : base(10) {
 		arr.resize(s.size());

 		for (size_t i = 0; i < s.size(); i++)
 			arr[i] = s[i] - '0';
 	}

 	void operator /= (int n) {
 	    vector <int> res;

 		int flag = 0;

 		for (size_t i = 0; i < arr.size(); i++) {
 			flag *= base;
 			flag += arr[i];
 			res.push_back(flag / n);
 			flag %= n;
 		}

 		while (flag >= n) {
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

 	void print() {
 		for (int i = arr.size() - 1; i >= 0; i--)
 			cout << arr[i];
 		cout << endl;	
 	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	cin >> s;

	big_int a(s);

	int n;
	cin >> n;

	a /= n;

	a.print();

	return 0;
}
