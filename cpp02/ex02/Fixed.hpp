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
	float	toFloat() const;
	int		toInt() const;
	static	Fixed	min(Fixed &a, Fixed &b);
	static	Fixed	min(const Fixed &a, const Fixed &b);
	static	Fixed	max(Fixed &a, Fixed &b);
	static	Fixed	max(const Fixed &a, const Fixed &b);
	void	operator=(const Fixed &original);
	bool	operator>(const Fixed &right) const;
	bool	operator<(const Fixed &right) const;
	bool	operator>=(const Fixed &right) const;
	bool	operator<=(const Fixed &right) const;
	bool	operator==(const Fixed &right) const;
	bool	operator!=(const Fixed &right) const;
	Fixed	operator+(const Fixed &right);
	Fixed	operator-(const Fixed &right);
	Fixed	operator*(const Fixed &right);
	Fixed	operator/(const Fixed &right);
	Fixed	&operator++();
	Fixed	&operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

};

std::ostream	&operator<<(std::ostream &out, const Fixed &fix);
#endif
