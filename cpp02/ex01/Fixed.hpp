#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed
{
private:
	int	_value;
	static const int	_fract = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &original);
	Fixed(const float f);
	Fixed(const int i);
	int		getRawBits() const;
	void	setRawBits(int const raw);
	void	operator=(const Fixed &original);
	float	toFloat() const;
	int		toInt() const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fix);
#endif
