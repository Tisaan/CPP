/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:07:39 by tseche            #+#    #+#             */
/*   Updated: 2026/04/17 16:30:12 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): nbr(0){
	std::cout << "default constructor called\n" << std::flush;
	this->nbr = 0;	
}

Fixed::Fixed(const Fixed &fix){
	*this = fix;
	std::cout << "copy constructor called\n" << std::flush;
}


Fixed::Fixed(const int nbr){
	std::cout << "Int constructor called\n" << std::flush;
	int tmp = nbr;
	this->nbr = roundf(static_cast<int>(nbr << this->fract));
}

Fixed::Fixed(const float nbr){
	std::cout << "Float constructor called\n" << std::flush;
	float tmp = nbr;
	this->nbr = roundf(static_cast<int>(tmp * (1 << this->fract)));
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
	return (static_cast<float>(this->nbr * (1 << this->fract)));
}

int Fixed::toInt() const{
	return (static_cast<int>(this->nbr * (1 << this->fract)));
}

int Fixed::getRawBits() const{
	std::cout << "getRawBits member function called\n" << std::flush;
	return this->nbr;
}

void Fixed::setRawBits(const int raw){
	std::cout << "setRawBits member function called\n" << std::flush;
	this->nbr = raw;
}
