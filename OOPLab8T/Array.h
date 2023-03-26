#pragma once
#include <iostream>

template<typename T>
class Array {
	T* arr;
	unsigned int size{};
	unsigned int lastElement{};
public:
	Array();
	Array(unsigned int size);
	~Array();
	unsigned int getSize();
	unsigned int getLength();

	bool resize(unsigned int size);
	bool append(T element);
	bool insert(T element, unsigned int index);
	bool remove(unsigned int index);
	T get(unsigned int index);
	void clear();

	T operator[](unsigned int index);
};





template<typename T>
inline Array<T>::Array() {
	size = 10;
	arr = new T[size];

	for (unsigned int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

template<typename T>
inline Array<T>::Array(unsigned int size) {
	this->size = size;
	arr = new T[size];

	for (unsigned int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

template<typename T>
inline Array<T>::~Array() {
	if (arr != 0) {
		delete[] arr;
	}
}





template<typename T>
unsigned int Array<T>::getSize() {
	return size;
}

template<typename T>
unsigned int Array<T>::getLength() {
	return lastElement;
}

template<typename T>
inline bool Array<T>::resize(unsigned int size) {
	T* oldPtr = arr;
	try {
		arr = new T[size];
	}
	catch (const std::exception&) {
		return false;
	}


	int maxIndex = this->size < size ? this->size : size;

	for (unsigned int i = 0; i < size; i++) {
		arr[i] = 0;
	}
	for (unsigned int i = 0; i < maxIndex; i++) {
		arr[i] = oldPtr[i];
	}

	this->size = size;
	delete[] oldPtr;
	return true;
}

template<typename T>
inline bool Array<T>::append(T element) {
	if (lastElement >= size) {
		if (!resize(size * 2)) {
			return false;
		}
	}

	arr[lastElement] = element;
	lastElement++;
	return true;
}

template<typename T>
inline bool Array<T>::insert(T element, unsigned int index) {
	if (lastElement >= size) {
		if (!resize(size * 2)) {
			return false;
		}
	}

	for (unsigned int i = lastElement - 1; i > index - 1; i--) {
		arr[i] = arr[i - 1];
	}
	arr[index] = element;
	return true;
}

template<typename T>
inline bool Array<T>::remove(unsigned int index) {
	if (index < lastElement) {
		arr[index] = 0;
		return true;
	}
	return false;
}

template<typename T>
inline T Array<T>::get(unsigned int index) {
	if (index < lastElement) {
		return arr[index];
	}
	return 0;
}

template<typename T>
inline void Array<T>::clear() {
	for (unsigned int i = 0; i < lastElement; i++) {
		arr[i] = 0;
	}
	lastElement = 0;
}

template<typename T>
inline T Array<T>::operator[](unsigned int index) {
	return get(index);
}
