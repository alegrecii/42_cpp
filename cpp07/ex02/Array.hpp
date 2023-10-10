#pragma once
#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
private:
	T *arr;
	unsigned int size;
public:
	Array() : arr(new T[0]), size(0){}

	Array(unsigned int &size) : arr(new T[size]), size(size){}

	Array(const Array &original)
	{
		*this = original;
	}

	Array &operator=(const Array &original)
	{
		T *tmp = new T[original.size];
		for (unsigned int i = 0; i < original.size; i++)
			tmp[i] = original[i];
		this->arr = tmp;
		this->size = original.size;
		return (*this);
	}

	T &operator[](unsigned int n) const
	{
		if (n >= this->size)
			throw std::runtime_error("The index is out of bounds!");
		return(this->arr[n]);
	}

	~Array()
	{
		delete[] this->arr;
	}

};

