#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	freopen("in", "w", stdout);

	ios_base :: sync_with_stdio(false);

	srand(time(NULL));

	int n = 1000000 + rand() % 1000000;

	cout << n << endl;

	set <int> s;

	for (int i = 0; i < n; i++) {
		int k = rand() % 3;

		switch (k) {
			case 0: {
				int val = rand() % 100000;
				cout << "+ " << val << endl;
				s.insert(val);
				break;
			}
			case 1: {
				int val = rand() % 100000;
				
				if (rand() & 1) {
					set <int> :: iterator it = s.lower_bound(val);
					
					if (it != s.end()) {
						cout << "- " << (*it) << endl;
						s.erase(it);
					} else
						cout << "- " << val << endl;
				} else {
					cout << "- " << val << endl;
					s.erase(val);
				}

			   	break;
			}

		   	case 2: {
		   		int val = rand() % 100000;
				
				if (rand() & 1) {
					set <int> :: iterator it = s.lower_bound(val);
					
					if (it != s.end())
						cout << "? " << (*it) << endl;
					else
						cout << "? " << val << endl;
				} else 
					cout << "? " << val << endl;
			   	
			   	break;
		   	}
		}
	}	

	return 0;
}
