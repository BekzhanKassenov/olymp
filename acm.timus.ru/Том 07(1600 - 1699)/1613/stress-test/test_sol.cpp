#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int block_size = 512;
int a[block_size * block_size];

struct Block {
 	int sorted_arr[block_size], unsorted_arr[block_size];
 	int len;

	Block() : len(0) { }

	void fill(int* mas, int l, int r) {
		for (int i = l; i <= r; i++) {
			sorted_arr[i & 511] = mas[i];
			unsorted_arr[i & 511] = mas[i];
		}	

		len = r - l + 1;
		sort(sorted_arr, sorted_arr + len);
	}

	bool find(int l, int r, int val) {
		for (int i = l; i <= r; i++)
			if (unsorted_arr[i] == val)
				return true;

	   	return false;
	}	
	
	bool find(int val) {
		return binary_search(sorted_arr, sorted_arr + len, val);
	}
};

struct sqrtDecomp {
 	Block a[block_size];
	
	sqrtDecomp() { }

	sqrtDecomp(int* arr, int n) {
		for (int i = 0; i <= n / block_size; i++) {
			a[i].fill(arr, i * block_size, min((i + 1) * block_size - 1, n - 1));
		}
	}

	bool find(int l, int r, int val) {
		if ((l >> 9) == (r >> 9))
			return a[l >> 9].find(l & 511, r & 511, val);

		bool flag = false;

		flag |= (a[l >> 9].find(l & 511, block_size - 1, val));
		flag |= (a[r >> 9].find(0, r & 511, val));

		for (int i = (l >> 9) + 1; i < (r >> 9) && !flag; i++)
			flag |= a[i].find(val);

		return flag;
	}
};

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
   	#endif

   	ios_base :: sync_with_stdio(false);

   	int n;
   	cin >> n;

   	for (int i = 0; i < n; i++)
   		cin >> a[i];
   	
   	sqrtDecomp dec(a, n);

   	int m;
   	cin >> m;

   	int l, r, val;

   	string res;

   	for (int i = 0; i < m; i++) {
   		cin >> l >> r >> val;

   		res += (dec.find(l - 1, r - 1, val) ? '1' : '0');
   	}

   	cout << res << endl;

   	return 0;
}
