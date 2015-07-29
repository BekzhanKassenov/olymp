#ifndef _HEAP_CPP_
#define _HEAP_CPP_

#include "heap.h"

template <typename T>
void Heap<T>::push_down(std::size_t position) {
	while (2 * position + 1 < heap_size) { // while not leaf
		std::size_t largest_child = 2 * position + 1; // left child

		if (elements[largest_child] > elements[largest_child + 1]) { // check right child
			largest_child++;
		}

		if (elements[position] <= elements[largest_child]) {
			break;
		}

		std::swap(elements[position], elements[largest_child]);
		position = largest_child;
	}
}

template <typename T>
void Heap<T>::push_up(std::size_t position) {
	while (position > 0 && elements[position] < elements[(position - 1) / 2]) {
		std::swap(elements[position], elements[(position - 1) / 2]);
		position = (position - 1) / 2;
	}
}

template <typename T>
Heap<T>::Heap() : heap_size(0u) { }

template <typename T>
Heap<T>::Heap(const std::vector<T>& elements) : elements(elements), heap_size(elements.size()) {
	for (int i = heap_size / 2; i >= 0; i--) {
		push_down(i);
	}
}
	
template <typename T>
Heap<T>::~Heap() { }

template <typename T>
void Heap<T>::add_element(const T& new_element) {
	if (heap_size >= elements.size()) {
		elements.push_back(new_element);
		heap_size = elements.size();
	} else {
		elements[heap_size] = new_element;
		heap_size++;
	}

	push_up(heap_size - 1);
}

template <typename T>
T Heap<T>::get_min_element() const {
	return elements[0];
}

template <typename T>
void Heap<T>::pop_element() {
	std::swap(elements[0], elements[heap_size - 1]);
	heap_size--;
	push_down(0);
}

template <typename T>
std::size_t Heap<T>::size() const {
	return heap_size;
}

template <typename T>
bool Heap<T>::empty() const {
	return heap_size == 0;
}

#endif // _HEAP_CPP_