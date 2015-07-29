#include <iostream>
#include <vector>
#include "heap.h"

using namespace std;

int main() {
	Heap <int> heap;

	for (int i = 0; i < 10; i++) {
		heap.add_element(i);
	}

	for (int i = 0; i < 5; i++) {
		cerr << heap.get_min_element() << endl;
		heap.pop_element();
	}

	for (int i = 0; i < 20; i++) {
		heap.add_element(i);
	}

	while (!heap.empty()){
		cerr << heap.get_min_element() << endl;
		heap.pop_element();
	}

	system("pause");

	return 0;
}
