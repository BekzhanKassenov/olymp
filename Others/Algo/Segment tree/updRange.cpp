#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

template <typename T>
void merge(const vector <T>& a, const vector <T>& b, vector <T>& res) {
	vector <T> :: iterator it_a = a.begin();
	vector <T> :: iterator it_b = b.begin();

	res.clear();

	while (it_a != a.end() && it_b != b.end()) {
		if (*it_a < *it_b) {
			res.push_back(*it_a);
			it_a++;
		} else {
			res.push_back(*it_b);
			it_b++;
		}
	}

	while (it_a != a.end()) {
		res.push_back(*it_a);
		it_a++;
	}

	while (it_b != b.end()) {
		res.push_back(*it_b);
		it_b++;
	}
}

template <typename T> 
bool bin_search(const vector <T>& a, T& val) {
	
}

int main() {
	freopen("in", "r", stdin);

}
