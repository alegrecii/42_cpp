#include "Point.hpp"

int main( void ) {

	Point	a(4, 6);
	Point	b(6,12);
	Point	c(10, 2);
	Point	p(6,6);

	if (bsp(a, b, c, p))
		std::cout << "The Point is inside" << std::endl;
	else
		std::cout << "The Point is outside" << std::endl;
	return 0;
}
