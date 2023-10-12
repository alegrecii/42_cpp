#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

class Span
{
private:
	std::vector<int> v;
	unsigned int N;
	Span();
public:
	Span(unsigned int n);
	Span(const Span &original);
	Span &operator=(const Span &original);
	void addNumber(int x);
	template <typename T>
	void addNumber(T start, T end)
	{
		if (this->v.size() + std::distance(start, end) <= this->N)
			this->v.insert(this->v.end(), start, end);
		else
			throw std::string("No more space in Span");
	}
	int shortestSpan();
	int longestSpan();

	~Span();
};

