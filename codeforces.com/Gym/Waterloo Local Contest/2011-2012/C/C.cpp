#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct big_int {
 	vector <int> arr;

 	big_int() { 
 		arr.push_back(1);
 	}

 	big_int(const vector <int>& arr) : arr(arr) { }

 	void operator += (big_int& p) {
 		int flag = 0;

 		size_t lena = p.arr.size();
 		size_t lenarr = arr.size();

 		for (size_t i = 0; i < max(lena, lenarr); i++) {
 			if (i < lena)
 				flag += p.arr[i];

 			if (i < lenarr) {
 				flag += arr[i];
 				arr[i] = flag % 10;
 				flag /= 10;
 			} else {
 				arr.push_back(flag % 10);
 				flag /= 10;
 			}
 		}

 		while (flag) {
 			arr.push_back(flag % 10);
 			flag /= 10;
 		}
 	}

 	void print() {
 		for (int i = arr.size() - 1; i >= 0; i--)
 			cout << arr[i];

 		cout << endl;	
 	}
};

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	if (n <= 2) {
		cout << 1;
		return 0;
	}

	big_int* n1 = new big_int();
	big_int* n2 = new big_int();

	for (int i = 3; i <= n; i++) {
		*n1 += *n2;
		swap(n1, n2);
	}

	n2 -> print();

	return 0;
}