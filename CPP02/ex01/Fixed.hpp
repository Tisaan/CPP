/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:06:40 by tseche            #+#    #+#             */
/*   Updated: 2026/04/17 14:47:43 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed{
	private:
		int nbr;
		static const int fract = 0U;
	public:
		Fixed();
		Fixed(const Fixed &fix);
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed &operator=(const Fixed &fix);
		~Fixed();

		float toFloat()const;
		int toInt()const;
		int getRawBits() const;
		void setRawBits(const int raw);
};

std::ostream &operator<<(std::ostream &stream, const Fixed &fix);