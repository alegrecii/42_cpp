#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	_value;
	static const int	_fract = 8;
	
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &original);
	int		getRawBits() const;
	void	setRawBits(int const raw);
	void	operator=(const Fixed &original);
};

#endif
