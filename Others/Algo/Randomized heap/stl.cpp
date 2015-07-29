#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

struct Heap {
  	vector <int> vec;
  	int size;

  	Heap() : size(0) { } 

  	void push_down(int pos) {
		while (2 * pos + 1 < size) {
		 	int j = 2 * pos + 1;

		 	if (vec[j] > vec[j + 1])
		 		j++;

		 	if (vec[pos] <= vec[j])
		 		break;

		 	swap(vec[j], vec[pos]);
		 	pos = j;	
		}
  	}

  	void push_up(int pos) {
		while (pos > 0 && vec[pos] < vec[(pos - 1) / 2]) {
		 	swap(vec[pos], vec[(pos - 1) / 2]);
		 	pos = (pos - 1) / 2;
		}
  	}

  	void push(int val) {
  	 	if (size < (int)vec.size()) {
  	 		vec[size++] = val;
  	 	} else {
  	 	 	vec.push_back(val);
  	 	 	size = vec.size();
  	 	}

  	 	push_up(size - 1);
  	}

  	int top() {
  	 	return vec[0];
  	}

  	void pop() {
  	 	vec[0] = vec[size - 1];
  	 	size--;
  	 	push_down(0);
  	}

  	bool empty() {
		return size == 0;
    }
};

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	freopen("log", "a", stderr);

	double start = clock();

	ios_base :: sync_with_stdio(false);

	int n;

	cin >> n;

	Heap q;

	for (int i = 0; i < n; i++)
		{
			char c;

			cin >> c;

			switch (c)
				{
					case '+':
						int k;
						cin >> k;

						q.push(k);

						break;

					case '-':
						if (!q.empty())
							{
								cout << q.top() << endl;
								q.pop();
							}
						else
							cout << -1 << endl;
						break;

					case '?':
						if (!q.empty())
							cout << q.top() << endl;	
						else
							cout << -1 << endl;
				}
		}

	fprintf(stderr, "%.3lf   ", ((clock() - start) / CLOCKS_PER_SEC));

 	return 0;
}
