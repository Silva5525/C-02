/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:15:35 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/24 14:01:20 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <utility>

/// @brief Fixed class that can store a fixed point value.
/// @private fixedPointValue and fractionalBits.
/// @public default constructor, copy constructor, copy assignment operator,
/// destructor && getRawBits() and setRawBits().
/// New in c++:
/// operator = is a function that assigns the value of the right operand
/// to the left operand.
/// From now on the have to follow the rule: your classes must be designed in the Orthodox
/// Canonical Form, except when explicitely stated otherwise.
/// That means you have to implement the default constructor, the copy constructor,
/// the assignation operator and the destructor. (the 4 after public:).
class Fixed
{
	private:
		int 				fixedPointValue;
		static const int	fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif
