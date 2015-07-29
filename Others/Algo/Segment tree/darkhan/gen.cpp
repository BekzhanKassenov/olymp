#include <bits/stdc++.h>

typedef long long i64;

using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	srand(time(NULL));
	stringstream ss;
    int n = 100000;
    int size = 200000;
    ss << n << endl;
    for (int j = 0; j < n; j++) {
    	int type = rand() % 3;
    	int l, r;
    		if (type == 0) {
    			l = rand() % size;
    			r = rand() % size;
    			l++; r++; 
    			if (l > r) swap(l, r);
    			ss << "ADD " << l << " " << r << " " << rand() % size - rand() % size << endl;

    	    }
    	    if (type == 1) {
    			l = rand() % size;
    			r = rand() % size;
    			l++; r++; 
    			if (l > r) swap(l, r);
    			ss << "GET " << l << " " << r << " " << endl;

			}
			if (type == 2) {
    			l = rand() % size;
    			r = rand() % size;
    			l++; r++; 
    			if (l > r) swap(l, r);
    			ss << "SET " << l << " " << r << " " << rand() % size - rand() % size << endl;

			}
    }

    cout << ss.str();
	return 0;
}
