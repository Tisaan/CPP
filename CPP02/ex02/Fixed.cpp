/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:07:39 by tseche            #+#    #+#             */
/*   Updated: 2026/04/18 17:08:34 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::fract = 8;

Fixed::Fixed(){
	this->nbr = 0;	
}

Fixed::Fixed(const Fixed &fix){
	*this = fix;
}


Fixed::Fixed(const int nbr){
	this->nbr = nbr << this->fract;
}

Fixed::Fixed(const float nbr){
	this->nbr = roundf(nbr * (1 << this->fract));
}
/*---------------[operator]---------------*/

Fixed &Fixed::operator=(const Fixed &fix){
	if (this != &fix)
		this->nbr = fix.getRawBits();
	return *this;
}

/*-----[comparison]-----*/

bool	Fixed::operator<(const Fixed &fix) const{
	return this->nbr < fix.nbr;
}

bool	Fixed::operator>(const Fixed &fix) const{
	return this->nbr > fix.nbr;
}

bool	Fixed::operator<=(const Fixed &fix) const{
	return this->nbr <= fix.nbr;
}

bool	Fixed::operator>=(const Fixed &fix) const{
	return this->nbr >= fix.nbr;
}

bool	Fixed::operator==(const Fixed &fix) const{
	return this->nbr == fix.nbr;
}

bool	Fixed::operator!=(const Fixed &fix) const{
	return this->nbr != fix.nbr;
}

/*-----[increment/decrement]-----*/

Fixed &Fixed::operator--(){
	this->nbr -= 1;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed	tmp = *this;
	this->nbr -= 1;
	return tmp;
}

Fixed &Fixed::operator++(){
	this->nbr += 1;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed tmp = *this;
	this->nbr += 1;
	return tmp;
}

/*-----[arithmetic]-----*/


Fixed	Fixed::operator*(const Fixed &a) const{
	Fixed res;
	res.setRawBits(this->getRawBits() * a.getRawBits() >> this->fract);
	return res;
}

Fixed	Fixed::operator/(const Fixed &a) const{
	return (Fixed((this->getRawBits() << this->fract) * a.getRawBits()));
}

Fixed	Fixed::operator+(const Fixed &a) const{
	return  Fixed(this->getRawBits() + a.getRawBits());
}

Fixed	Fixed::operator-(const Fixed &a) const{
	return  Fixed(this->getRawBits() - a.getRawBits());
}

/*-----[print]-----*/

std::ostream &operator<<(std::ostream &stream, const Fixed &fix){
	stream << fix.toFloat();
	return stream;
}

/*---------------[destructor]---------------*/

Fixed::~Fixed(){
}

/*---------------[method]---------------*/

Fixed &Fixed::min(Fixed &a, Fixed &b){
	return (a <= b) ? a : b;	
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	return (a <= b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	return (a >= b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	return (a >= b) ? a : b;
}

float Fixed::toFloat() const{
	return (static_cast<float>(this->nbr) / (1 << this->fract));
}

int Fixed::toInt() const{
	return (this->nbr >> this->fract);
}

int Fixed::getRawBits() const{
	return this->nbr;
}

void Fixed::setRawBits(const int raw){
	this->nbr = raw;
}
