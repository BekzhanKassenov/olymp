#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

#define all(x) (x).begin(), (x).end()

const int base = 2;

struct big_int {
	vector <int> arr;
	big_int() {}

	big_int(long long n) {
		while (n) {
			arr.push_back(n % 10);
			n /= 10;
		}

		if (arr.empty())
			arr.push_back(0);
	}

	big_int(int n) {
		while (n) {
			arr.push_back(n % 10);
			n /= 10;
		}

		if (arr.empty())
			arr.push_back(0);
	}

	void delete_zeroes() {
		while (!arr.empty() && arr.back() == 0)
			arr.pop_back();

		if (arr.empty())
			arr.push_back(0);
	}

	void operator *= (int k) {
		long long flag = 0;

		for (size_t i = 0; i < arr.size(); i++) {
			flag += arr[i] * k;
			arr[i] = flag % 10;
			flag /= 10;
		}

		while (flag) {
			arr.push_back(flag % 10);
			flag /= 10;
		}

		delete_zeroes();
	}

	void div_by_ten() {
		reverse(all(arr));
		if (!arr.empty())
			arr.pop_back();

		if (arr.empty())
			arr.push_back(0);

		reverse(all(arr));	
	}

	int mod_ten() {
		if (arr.empty())
			return 0;

		return arr[0];	
	}

	bool operator == (big_int& p) {
		p.delete_zeroes();
		delete_zeroes();

		return (arr == p.arr);
	}

	void print() {
		for (int i = arr.size() - 1; i >= 0; i--)
			cout << arr[i];
		cout << endl;	
	}
};

bool operator == (big_int& p, int n) {
	big_int tmp(n);

	return (p == tmp);
}

int main() {
	freopen("transformations.in", "r", stdin);

	ios_base :: sync_with_stdio(false);

	stringstream ss;

	string res;
	int k;
	cin >> k;
	long long n;

	while (k--) {
		cin >> n;
 		res = "";

 		big_int a(n);

		while (!(a == 4)) {
        	big_int md = a.mod_ten();
                
           	if (md == 4) {
                res += 'B';
                a.div_by_ten();
            } else if (md == 0) {
                res += 'A';
                a.div_by_ten();
            } else if (md == 2 || md == 5 || md == 7) {
                a *= 2;
                res += 'C';
            } else if (md == 1 || md == 6) {
               	a *= 4;
                res += "CC";
            } else if (md == 3 || md == 8) {
                a *= 8;
                res += "CCC";
            } else if (md == 9) {
                a *= 16;
                res += "CCCC";
            }

            //a.print();

            if (res.size() > 200) {
            	ss << -1 << endl;
            	goto skip;	
            }
       	}
       	reverse(all(res));
       	ss << res << endl;
       	skip:;
	}

	cout << ss.str();

	return 0;


}
