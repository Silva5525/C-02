/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:15:27 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/21 18:13:53 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/// @brief Default constructor sets by default the fixedPointValue to 0.
/// and prints a message.
Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/// @brief Integer constructor sets the fixedPointValue to the value
/// of the integer value.
/// @param val the integer value which should be stored.
/// Shift left by the number of fractional bits to get the 
/// fixed point value.
Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	fixedPointValue = val << fractionalBits;
}

/// @brief Constructor which sets the fixedPointValue to the value
/// of the float value. 
/// @param val the float value which should be stored.
/// Scale and round the float value to the fixed point value.
/// @note new in c++:
/// @fn roundf() rounds the float value to the nearest integer value.
Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	fixedPointValue = static_cast<int>(roundf(val * (1 << fractionalBits)));
}

/// @brief Copy constructor sets the fixedPointValue to the value
/// of the other object.
/// @param other value which should be copied.
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointValue = other.getRawBits();
}

/// @brief Copy assignment operator sets the fixedPointValue to
/// the value of the other object.
/// @param other value which should be copied.
/// @return the pointer to the object.
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointValue = other.getRawBits();
	return (*this);
}

/// @brief The destructor which prints a message after the object
/// is destroyed.
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/// @brief Returns the fixedPointValue.
/// @return the this pointer to the fixedPointValue.
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

/// @brief sets the fixedPointValue to the raw value.
/// @param raw becomming the new fixedPointValue.
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}

/// @brief Converts the fixed-point value to a floating-point value and returns it.
/// The fixed-point value is divided by 2^_fractionalBits to scale it down.
/// static_cast<float> ensures the result of the division is a floating-point number.
/// Using (1 << _fractionalBits) efficiently represents 2^_fractionalBits,
/// aligning with bitwise fixed-point arithmetic principles.
float Fixed::convertFloat(void) const
{
	return (static_cast<float>(fixedPointValue) / (1 << fractionalBits));
}

/// @brief Converts the fixed-point value to an integer by discarding the fractional part.
/// @details This is done by shifting the fixed-point value to the right by the number 
/// of fractional bits (equivalent to dividing by 2^fractionalBits).
int Fixed::convertInt(void) const
{
	return (fixedPointValue >> fractionalBits);
}

/// @brief Overloads the insertion operator to output a Fixed object.
/// Outputs the floating-point representation of the fixed-point value
/// by calling convertFloat(). This ensures a human-readable output
/// that matches the expected behavior of a floating-point number.
std::ostream& operator<<(std::ostream& out, const Fixed& fix)
{
	out << fix.convertFloat();
	return (out);
}
