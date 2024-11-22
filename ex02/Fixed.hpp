/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:15:35 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/22 17:16:41 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <iomanip>

/// @brief Fixed class that can store a fixed point value.
/// @private fixedPointValue and fractionalBits.
/// @public default constructor, integer constructor, float constructor,
/// copy constructor, copy assignment operator,
/// destructor && getRawBits() and setRawBits(),
/// convertFloat() and convertInt() , << operator.
/// all comparison operators, arithmetic operators,
/// increment and decrement operators, min and max functions.
class Fixed
{
	private:
		int 				fixedPointValue;
		static const int	fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		/// comparison operators
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;

		/// arithmetic operators
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;

		/// increment and decrement operators
		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		/// min and max functions with and without const
		static Fixed&		min(Fixed& left, Fixed& right);
		static Fixed&		max(Fixed& left, Fixed& right);
		static const Fixed&	min(const Fixed& left, const Fixed& right);
		static const Fixed&	max(const Fixed& left, const Fixed& right);
		
		int					getRawBits() const;
		void				setRawBits(int const raw);
		float				convertFloat(void) const;
		int					convertInt(void) const;
		static std::ostream& print(std::ostream& out, const Fixed& fix);
};

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
	std::ostream& operator<<(std::ostream& out, const Fixed& fix);

#endif
