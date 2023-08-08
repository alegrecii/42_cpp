#include "Point.hpp"

int main( void ) {

	Point	a(4, 1);
	Point	b(6,2);
	Point	c(4, 8);
	Point	p(5.84, 5.25);

	if (bsp(a, b, c, p))
		std::cout << "The Point is inside" << std::endl;
	else
		std::cout << "The Point is outside" << std::endl;
	return 0;
}
