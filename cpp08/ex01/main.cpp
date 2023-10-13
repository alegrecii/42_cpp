#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;

		Span sp2(10000);
		std::vector<int> v;
		for (int i = 0; i < 10000; i++)
			v.push_back(i);
		sp2.addNumber(v.begin(), v.end());
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
		std::cout << std::endl;

		Span sp3(1);
		sp3.addNumber(1);
		sp3.addNumber(2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
