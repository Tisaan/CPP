/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:07:39 by tseche            #+#    #+#             */
/*   Updated: 2026/04/17 14:37:01 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "default constructor called\n" << std::flush;
	this->nbr = 0;	
}

Fixed::Fixed(const Fixed &fix){
	this->nbr = fix.nbr;
	std::cout << "copy constructor called\n" << std::flush;
}

Fixed::~Fixed(){
	std::cout << "destructor called\n" << std::flush;
}

Fixed &Fixed::operator=(Fixed &fix){
	std::cout << "copy assignement operator called\n" << std::flush;
	return fix;
}

int Fixed::getRawBits() const{
	std::cout << "getRawBits member function called\n" << std::flush;
	return this->nbr;
}

void Fixed::setRawBits(const int raw){
	std::cout << "setRawBits member function called\n" << std::flush;
	this->nbr = raw;
}
