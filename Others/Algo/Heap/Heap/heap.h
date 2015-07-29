#ifndef _HEAP_H_
#define _HEAP_H_

#include <algorithm>
#include <vector>

/*
	root = 0
	left child of i = 2 * i + 1;
	right child of i = 2 * i + 2;
	parent(i) = (i - 1) / 2, provided that i is not root
*/
template <typename T>
class Heap {
private:	
	std::vector <T> elements;
	std::size_t heap_size;

	void push_down(std::size_t position);
	void push_up(std::size_t position);

public:
	Heap();
	Heap(const std::vector<T>& elements);
	~Heap();

	void add_element(const T& new_element);
	T get_min_element() const;
	void pop_element();

	std::size_t size() const;
	bool empty() const;
};

#include "heap.cpp"
#endif // _HEAP_H_