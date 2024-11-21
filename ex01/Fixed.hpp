/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:15:35 by wdegraf           #+#    #+#             */
/*   Updated: 2024/11/21 17:47:17 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <utility>
# include <cmath>

/// @brief Fixed class that can store a fixed point value.
/// @private fixedPointValue and fractionalBits.
/// @public default constructor, integer constructor, float constructor,
/// copy constructor, copy assignment operator,
/// destructor && getRawBits() and setRawBits(),
/// convertFloat() and convertInt() , << operator.
/// New in c++:
/// @fn friend: makes it possible to access the private members of the class.
/// so operator << can access the private members of the class.
/// @fn operator<<: takes a output stream and the object you want to print.
/// it returns an ostream& so you multiple chaning is possible. 
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

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	convertFloat(void) const;
		int		convertInt(void) const;
		friend	std::ostream& operator<<(std::ostream& out, const Fixed& fix);
};

#endif
