#include "Span.hpp"

Span::Span() : N(0)
{
}

Span::Span(unsigned int n) : N(n)
{
}

Span::Span(const Span &original)
{
	*this = original;
}

Span &Span::operator=(const Span &original)
{
	this->N = original.N;
	return (*this);
}

void Span::addNumber(int x)
{
	if (this->v.size() < this->N)
		this->v.push_back(x);
	else
		throw std::out_of_range("the vector is full");
}

int Span::shortestSpan()
{
	if(this->v.size() < 2)
		throw std::out_of_range("Not enough numbers to calculate span");
	std::vector<int> tmp = this->v;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 2; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

int Span::longestSpan()
{
	if(this->v.size() < 2)
		throw std::out_of_range("Not enough numbers to calculate span");
	std::vector<int> tmp = this->v;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

Span::~Span()
{
}
