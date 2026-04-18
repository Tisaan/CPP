/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:06:40 by tseche            #+#    #+#             */
/*   Updated: 2026/04/18 17:06:02 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed{
	private:
		int nbr;
		static const int fract;
	public:
		Fixed();
		Fixed(const Fixed &fix);
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed &operator=(const Fixed &fix);
		//comparison operator
		bool	operator>(const Fixed &fix) const;
		bool	operator<(const Fixed &fix) const;
		bool	operator>=(const Fixed &fix) const;
		bool	operator<=(const Fixed &fix) const;
		bool	operator==(const Fixed &fix) const;
		bool	operator!=(const Fixed &fix) const;
		Fixed	&operator++();
		Fixed	operator++(int a);
		Fixed	&operator--();
		Fixed	operator--(int a);
		Fixed	operator*(const Fixed &a) const;
		Fixed	operator/(const Fixed &a) const;
		Fixed	operator+(const Fixed &a) const;
		Fixed	operator-(const Fixed &a) const;

		~Fixed();

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		float toFloat()const;
		int toInt()const;
		int getRawBits() const;
		void setRawBits(const int raw);
};

std::ostream &operator<<(std::ostream &stream, const Fixed &fix);