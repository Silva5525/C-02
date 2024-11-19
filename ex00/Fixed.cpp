/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:15:27 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/19 15:46:39 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/// @brief Default constructor sets by default the fixedPointValue to 0.
/// and prints a message.
Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
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
