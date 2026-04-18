/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:07:39 by tseche            #+#    #+#             */
/*   Updated: 2026/04/18 16:45:13 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::fract = 8;

Fixed::Fixed(){
	std::cout << "default constructor called\n" << std::flush;
	this->nbr = 0;	
}

Fixed::Fixed(const Fixed &fix){
	*this = fix;
	std::cout << "copy constructor called\n" << std::flush;
}


Fixed::Fixed(const int nbr){
	std::cout << "Int constructor called\n" << std::flush;
	this->nbr = nbr << this->fract;
}

Fixed::Fixed(const float nbr){
	std::cout << "Float constructor called\n" << std::flush;
	this->nbr = roundf(nbr * (1 << this->fract));
}

Fixed &Fixed::operator=(const Fixed &fix){
	std::cout << "copy assignement operator called\n" << std::flush;
	if (this != &fix)
		this->nbr = fix.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &fix){
	stream << fix.toFloat();
	return stream;
}

Fixed::~Fixed(){
	std::cout << "destructor called\n" << std::flush;
}

float Fixed::toFloat() const{
	return (static_cast<float>(this->nbr) / (1 << this->fract));
}

int Fixed::toInt() const{
	return (this->nbr >> this->fract);
}

int Fixed::getRawBits() const{
	std::cout << "getRawBits member function called\n" << std::flush;
	return this->nbr;
}

void Fixed::setRawBits(const int raw){
	std::cout << "setRawBits member function called\n" << std::flush;
	this->nbr = raw;
}
