/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:06:40 by tseche            #+#    #+#             */
/*   Updated: 2026/04/17 14:36:53 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed{
	private:
		int nbr;
		static const int fract = 0U;
	public:
		Fixed(const Fixed &fix);
		Fixed &operator=(Fixed &fix);

		int getRawBits() const;
		void setRawBits(const int raw);

		Fixed();
		~Fixed();
};