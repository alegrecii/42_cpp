#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const float f)
{
	_value = (int)roundf(f * (1 << _fract));
}

Fixed::Fixed(const int i)
{
	_value = i << this->_fract;
}

Fixed::Fixed(const Fixed &original)
{
	this->_value = original.getRawBits();
}

int	Fixed::getRawBits() const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat() const
{
	return ((float)this->_value / (1 << this->_fract));
}

int Fixed::toInt() const
{
	return ((int)(roundf((float)this->_value / (1 << this->_fract))));
}


void	Fixed::operator=(const Fixed &original)
{
	this->_value = original.getRawBits();
}

bool	Fixed::operator>(const Fixed &right) const
{
	if (this->toFloat() > right.toFloat())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed &right) const
{
	if (this->toFloat() < right.toFloat())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed &right) const
{
	if (this->toFloat() >= right.toFloat())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed &right) const
{
	if (this->toFloat() <= right.toFloat())
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed &right) const
{
	if (this->toFloat() == right.toFloat())
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed &right) const
{
	if (this->toFloat() != right.toFloat())
		return (true);
	else
		return (false);
}

Fixed	Fixed::operator+(const Fixed &right)
{
	float	tmp;

	tmp = this->toFloat() + right.toFloat();
	return (Fixed(tmp));
}

Fixed	Fixed::operator-(const Fixed &right)
{
	float	tmp;

	tmp = this->toFloat() - right.toFloat();
	return (Fixed(tmp));
}

Fixed	Fixed::operator*(const Fixed &right)
{
	float	tmp;

	tmp = this->toFloat() * right.toFloat();
	return (Fixed(tmp));
}

Fixed	Fixed::operator/(const Fixed &right)
{
	float	tmp;

	tmp = this->toFloat() / right.toFloat();
	return (Fixed(tmp));
}


Fixed	&Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	_value++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_value--;
	return (tmp);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fix)
{
	out << fix.toFloat();
	return (out);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
