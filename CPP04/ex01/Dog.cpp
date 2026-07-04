/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:16:12 by tseche            #+#    #+#             */
/*   Updated: 2026/07/04 14:05:22 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Dog::Dog(): Animal(){
	std::cout << "|Dog| default constructor called\n" << std::flush;
	this->type = "Dog";
	this->b = new Brain();
}

Dog::Dog(const Dog &dog): Animal(){
	std::cout << "|Dog| default constructor called\n" << std::flush;
	if (this != &dog)
		*this = dog;
}

const Dog &Dog::operator=(const Dog &dog){
	if (this != &dog)
		*this = dog;
	return (dog);
}

Dog::~Dog(){
	std::cout << "|Dog| destructor called\n" << std::flush;
	delete this->b;
}

std::string Dog::getType() const{
	return this->type;
}

void Dog::makeSound() const {
	std::cout << "whouaf\n" << std::flush;
}