/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:15:27 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/22 17:08:43 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/// @brief Default constructor sets by default the fixedPointValue to 0.
Fixed::Fixed() : fixedPointValue(0) {}

/// @brief The destructor does nothing becouse we dont use new.
Fixed::~Fixed() {}

/// @brief Integer constructor sets the fixedPointValue to the value
/// of the integer value.
/// @param val the integer value which should be stored.
/// Shift left by the number of fractional bits to get the 
/// fixed point value.
Fixed::Fixed(const int val)
{
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
	fixedPointValue = static_cast<int>(roundf(val * (1 << fractionalBits)));
}

/// @brief Copy constructor sets the fixedPointValue to the value
/// of the other object.
/// @param other value which should be copied.
Fixed::Fixed(const Fixed& other)
{
	this->fixedPointValue = other.getRawBits();
}

/// @brief Copy assignment operator sets the fixedPointValue to
/// the value of the other object.
/// @param other value which should be copied.
/// @return the pointer to the object.
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->fixedPointValue = other.getRawBits();
	return (*this);
}

/// @brief Returns the fixedPointValue.
/// @return the this pointer to the fixedPointValue.
int Fixed::getRawBits() const
{
	return (this->fixedPointValue);
}

/// @brief sets the fixedPointValue to the raw value.
/// @param raw becomming the new fixedPointValue.
void Fixed::setRawBits(int const raw)
{
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

/// @brief printing method for the Fixed class.
std::ostream& Fixed::print(std::ostream& out, const Fixed& fix)
{
	out << fix.convertFloat();
	return (out);
}

/// @brief Overloads the insertion operator (<<) for the Fixed class.
/// Since the `friend` keyword is forbidden in this project, we cannot declare 
/// the `operator<<` function as a friend to access the private members of the Fixed class.
/// To resolve this, we use the `print` static member function to access
/// and format the Fixed class's data.
/// The `print` function acts as an intermediary, ensuring encapsulation while
/// complying with the project rules.
/// 
/// @param out The output stream to which the Fixed object will be written.
/// @param fix The Fixed object to be printed.
/// @return A reference to the modified output stream (enabling chaining).
std::ostream& operator<<(std::ostream& out, const Fixed& fix)
{
	return (Fixed::print(out, fix));
}

/// @brief Overloads comparison operators for the Fixed class.
/// @details These operators compare the fixed-point values (fixedPointValue) of 
/// two Fixed objects. They enable comparisons such as equality, inequality, 
/// greater-than, less-than, greater-than-or-equal-to, and less-than-or-equal-to.
/// 
/// The operators perform the following checks:
/// - `==`: Returns true if the values are equal.
/// - `!=`: Returns true if the values are not equal.
/// - `<`: Returns true if the current object’s value is less than the other’s.
/// - `>`: Returns true if the current object’s value is greater than the other’s.
/// - `<=`: Returns true if the current object’s value is less than or equal to the other’s.
/// - `>=`: Returns true if the current object’s value is greater than or equal to the other’s.
///
/// These operators allow Fixed objects to be used in logical expressions 
/// and sorted in collections, if necessary.
///
/// @param other The Fixed object to compare with.
/// @return A boolean result depending on the comparison.
bool	Fixed::operator==(const Fixed& other) const
{
	return (this->fixedPointValue == other.fixedPointValue);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->fixedPointValue != other.fixedPointValue);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->fixedPointValue < other.fixedPointValue);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->fixedPointValue > other.fixedPointValue);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->fixedPointValue <= other.fixedPointValue);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->fixedPointValue >= other.fixedPointValue);
}

/// @brief Overloads arithmetic operators for the Fixed class.
/// @details These operators allow Fixed objects to participate in arithmetic 
/// operations such as addition, subtraction, multiplication, and division. 
/// The operators work on the floating-point representation of the fixed-point values 
/// and return a new Fixed object with the result.
/// 
/// The operators perform the following operations:
/// - `+`: Adds the fixed-point value of the current object to the other object’s value.
/// - `-`: Subtracts the other object’s fixed-point value from the current object’s value.
/// - `*`: Multiplies the fixed-point values of the current and other object.
/// - `/`: Divides the fixed-point value of the current object by the other object’s value. 
///   - Note: Division by zero will only throw a runtime error if u change / to the commented one.
/// 
/// These operators provide natural arithmetic behavior for Fixed objects, 
/// facilitating their use in mathematical expressions.
/// 
/// @param other The Fixed object to perform the operation with.
/// @return A new Fixed object containing the result of the operation.
/// @note new in c++:
/// @fn runtime_error() throws an exception of type runtime_error with a message.
Fixed	Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->convertFloat() * other.convertFloat()));
}

// Fixed	Fixed::operator/(const Fixed& other) const
// {
// 	return (Fixed(this->convertFloat() / other.convertFloat()));
// }

/// if you want that it crashes by Division by zero use this.. 
Fixed	Fixed::operator/(const Fixed& other) const
{
	if (other.getRawBits() == 0)
		throw std::runtime_error("Division by zero");
	return (Fixed(this->convertFloat() / other.convertFloat()));
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->convertFloat() + other.convertFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->convertFloat() - other.convertFloat()));
}

/// @brief Pre-increment
Fixed&	Fixed::operator++(void)
{
	this->fixedPointValue++;
	return (*this);
}

/// @brief Pre-decrement
Fixed&	Fixed::operator--(void)
{
	this->fixedPointValue--;
	return (*this);
}

/// @brief Post-increment
Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++(*this);
	return (tmp);
}

/// @brief Post-decrement
Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--(*this);
	return (tmp);
}

/// @brief min returns the smaller Fixed object of two Fixed objects.
/// @param left Fixed object.
/// @param right Fixed object.
/// @return the smaller Fixed object.
Fixed&	Fixed::min(Fixed& left, Fixed& right)
{
	return (left < right ? left : right);
}

/// @brief max returns the bigger Fixed object of two Fixed objects.
/// @param left Fixed object.
/// @param right Fixed object.
/// @return the bigger Fixed object.
Fixed&	Fixed::max(Fixed& left, Fixed& right)
{
	return (left > right ? left : right);
}

/// @brief min returns the smaller const Fixed object of two const Fixed objects.
/// @param left const Fixed object.
/// @param right const Fixed object.
/// @return the smaller const Fixed object.
const Fixed&	Fixed::min(const Fixed& left, const Fixed& right)
{
	return (left < right ? left : right);
}

/// @brief max returns the bigger const Fixed object of two const Fixed objects.
/// @param left const Fixed object.
/// @param right const Fixed object.
/// @return the bigger const Fixed object.
const Fixed&	Fixed::max(const Fixed& left, const Fixed& right)
{
	return (left > right ? left : right);
}
