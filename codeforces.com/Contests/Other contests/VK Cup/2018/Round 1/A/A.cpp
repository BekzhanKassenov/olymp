#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <string>
#include <sstream>
#include <math.h>
#include <stack>
 
using namespace std;
 
const int N = 1000000 + 100;
 
bool is_prime[N];
 
int main() {
 
	//freopen("in.txt", "r", stdin);
	//freopen("test.txt", "w", stdout);
 
	vector<int> primes;
 
	for (int i = 2; i < N; ++i) {
		is_prime[i] = 1;
	}
 
	for (int i = 2; i < N; ++i) {
		if (is_prime[i]) {
			for (long long j = 2 * i; j < N; j += i) {
				is_prime[j] = 0;
			}
			primes.push_back(i);
		}
	}
 
	long long x2;
	cin >> x2;
 
	long long min_x1 = x2;
	for (int i = 0; i < primes.size(); ++i) {
		int p = primes[i];
		if (x2 % p == 0) {
			long long to = x2 - p + 1;
			if (to < 3) {
				to = 3;
			}
			if (to < p) {
				to = p + 1;
			}
 
			if (to < min_x1) min_x1 = to;
		}
	}
 
	int min_x0 = min_x1;
 
	for (int i = 0; i < primes.size(); ++i) {
		int p = primes[i];
		int add = p - min_x1 % p;
		if (add == p) add = 0;
		int from = min_x1 + add;
 
		if (from <= x2) {
			int to = from - p + 1;
			if (to < 3) to = 3;
			if (to < p) to = p + 1;
			if (to < min_x0) {
				min_x0 = to;
			}
		}
		
	}
 
	cout << min_x0;
 
	
 
	return 0;
}
