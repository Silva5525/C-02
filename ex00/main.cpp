/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:15:48 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/19 17:11:47 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/// @brief main from the subjekt.
/// prints the raw bits of a, b and c.
/// get_raw_bits() returns the fixedPointValue.
/// set_raw_bits() sets the fixedPointValue. (not used in this main)
/// initializes a to 0 in the default constructor.
/// initializes b to a in the copy constructor.
/// initializes c to b in the copy assignment operator.
/// on return it called the destructor for a, b and c.
/// @note New in c++:
/// operator = is a function that assigns the value of the right operand
/// to the left operand. (check in Fixed.cpp)
int	main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}

// /// @brief test main for Fixed class.
// /// Initializes a to 0 in the default constructor and prints the raw bits.
// /// Sets the raw bits to -42 and prints the raw bits.
// /// Initializes b to a in the copy constructor and prints the raw bits. (should be the same as a)
// /// Initializes c to b in the copy assignment operator and prints the raw bits. (should be the same as a)
// /// Sets the raw bits to -123 and prints the raw bits.
// /// on return it called the destructor for a, b and c.
// int main(void)
// {
// 	Fixed a;
// 	std::cout << "Raw bits (a): " << a.getRawBits() << std::endl;

// 	a.setRawBits(-42);
// 	std::cout << "Raw bits after set (a): " << a.getRawBits() << std::endl;

// 	Fixed b(a);
// 	std::cout << "Raw bits (b): " << b.getRawBits() << std::endl;

// 	Fixed c;
// 	c = b;
// 	std::cout << "Raw bits (c): " << c.getRawBits() << std::endl;

// 	a.setRawBits(-123);
// 	std::cout << "Raw bits after negative set (a): " << a.getRawBits() << std::endl;

// 	return (0);
// }


// just some math functions in c
// ========================================================================== //
// #include <math.h>
// /// @brief used to calculate the magnitude of a complex number.
// /// @param re real part of the complex number.
// /// @param im imaginary part of the complex number.
// /// @return the magnitude of the complex number.
// /// @fn fabs() returns the absolute value of a floating point number.
// /// @fn sqrt() returns the square root of a floating point number.
// /// @attention hypot(re , im) would also do the trick but slower.. man hypot.
// double magnitude(double re, double im)
// {
// 	double r;

// 	re = fabs(re);
// 	im = fabs(im);
// 	if (re > im)
// 	{
// 		r = im/re;
// 		return re*sqrt(1.0+r*r);
// 	}
// 	if (im == 0.0)
// 		return (0.0);
// 	r = re/im;
// 	return im*sqrt(1.0+r*r);
// }

// #include <ieee754.h>
// #define LOG2_10 3.321928095

// #define flt_zero(x) (fabs(x) < EPSILON)
 
// int max_digs_rt = 3;  /* maximum # of 0's right of decimal before using
// 						scientific notation */
// int max_digs_lf = 5;  /* max # of digits left of decimal */

// /// @brief Prints the number specified by `r`. The formatting and precision 
// /// are controlled by `width` and `dec`. 
// /// If `width` is 0, the number is printed in the default format.
// /// If `width` is not 0, the number is printed in a format with the 
// /// specified width and decimal places.
// /// @param r The number to be printed.
// /// @param width The minimum field width for the output. If 0, no specific width is used.
// /// @param dec The number of decimal places in the output.
// void print_real(double r, int width, int dec)
// {
// 	int mag;
// 	double fpart, temp;
// 	char format[8];
// 	char num_format[3] = {'l',0,0};
// 	union ieee754_double *dl;

// 	dl = (union ieee754_double*)&r;
// 	mag = (dl->ieee.exponent - IEEE754_DOUBLE_BIAS) / LOG2_10;
// 	if (r == 0)
// 		mag = 0;
// 	if ((mag > max_digs_lf-1) || (mag < -max_digs_rt)) {
// 		num_format[1] = 'e';
// 		temp = r/pow(10, mag);      /* see if number will have a decimal */
// 		fpart = temp - floor(temp); /* when written in scientific notation */
// 	}
// 	else {
// 		num_format[1] = 'f';
// 		fpart = r - floor(r);
// 	}
// 	if (flt_zero(fpart))
// 		dec = 0;
// 	if (width == 0) {
// 		snprintf(format, 8, "%%.%d%s", dec, num_format);
// 	}
// 	else {
// 		snprintf(format, 8, "%%%d.%d%s", width, dec, num_format);
// 	}
// 	printf(format, r);
// }
