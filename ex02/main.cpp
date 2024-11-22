/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:15:48 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/22 13:59:08 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// /// @brief main function from the main
// /// @note new in c++: (runtime_error you find it in the Fixed.cpp line 181-187)
// /// @fn runtime_error() throws an exception of type runtime_error with a message.
// int main( void ) {
// Fixed a;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;

// std::cout << b << std::endl;

// std::cout << Fixed::max( a, b ) << std::endl;

// return 0;
// }

/// @brief main function for testing all cases.
/// @note new in c++: (runtime_error you find it in the Fixed.cpp line 181-187)
/// std::exception is the base class for all standard C++ exceptions.
/// @fn runtime_error() throws an exception of type runtime_error with a message.
/// @fn .what() returns a C-style character string describing the general cause
/// of the current error (the same string passed to the ctor).
/// in this case it is "Division by zero".from the runtime_error function.
int main(void) 
{
	// Testing constructors
	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(b);

	std::cout << "\n=== Constructors ===" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;

	// Testing comparison operators
	std::cout << "\n=== Comparison Operators ===" << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "b <= d: " << (b <= d) << std::endl;
	std::cout << "b >= d: " << (b >= d) << std::endl;
	std::cout << "b == d: " << (b == d) << std::endl;
	std::cout << "b != d: " << (b != d) << std::endl;

	// Testing arithmetic operators
	std::cout << "\n=== Arithmetic Operators ===" << std::endl;
	Fixed e = b + c;
	Fixed f = c - b;
	Fixed g = b * c;
	Fixed h = c / b;
	std::cout << "b + c: " << e << std::endl;
	std::cout << "c - b: " << f << std::endl;
	std::cout << "b * c: " << g << std::endl;
	std::cout << "c / b: " << h << std::endl;

	// Testing increment/decrement operators
	std::cout << "\n=== Increment/Decrement Operators ===" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;

	// Testing min/max functions
	std::cout << "\n=== Static Min/Max Functions ===" << std::endl;
	std::cout << "Min of b and c: " << Fixed::min(b, c) << std::endl;
	std::cout << "Max of b and c: " << Fixed::max(b, c) << std::endl;

	const Fixed constA = c;
	const Fixed constB = b;
	std::cout << "Min of constA and constB: " << Fixed::min(constA, constB) << std::endl;
	std::cout << "Max of constA and constB: " << Fixed::max(constA, constB) << std::endl;

	// Edge case: division by zero
	std::cout << "\n=== Division by Zero (Expected Crash or Error) ===" << std::endl;
	try {
		Fixed zero;
		Fixed result = c / zero;
		std::cout << "c / zero: " << result << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
