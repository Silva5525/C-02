/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:15:48 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/22 16:57:12 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/// @brief main for  printing the fixed point value of a, b, c and d.
/// a is initialized with a float value. b is initialized with an integer value.
/// c is initialized with a float value. d is initialized with b.
/// prints the fixed point value of a, b, c and d.
/// prints the integer value of a, b, c and d.
/// @note New in c++:
/// std::ostream is used to output the fixed point value of an object.
/// @fn roundf() rounds the float value to the nearest integer value.
/// @fn operator<<: takes a output stream and the object you want to print.
/// it returns an ostream& so you multiple chaning is possible.
/// @fn convertFloat() check it in Fixed.cpp.
/// @fn convertInt() check it in Fixed.cpp.
int	main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.convertInt() << " as integer" << std::endl;
	std::cout << "b is " << b.convertInt() << " as integer" << std::endl;
	std::cout << "c is " << c.convertInt() << " as integer" << std::endl;
	std::cout << "d is " << d.convertInt() << " as integer" << std::endl;

	return (0);
}
