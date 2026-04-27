/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:16:12 by tseche            #+#    #+#             */
/*   Updated: 2026/04/27 16:18:45 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Dog::Dog(){
	std::cout << "|Dog| default constructor called\n" << std::flush;
	this->type = "Dog";
}

Dog::Dog(Dog &dog){
	std::cout << "|Dog| default constructor called\n" << std::flush;
	if (this != &dog)
		*this = dog;
}

Dog &Dog::operator=(Dog &dog){
	if (this != &dog)
		*this = dog;
	return (dog);
}

Dog::~Dog(){
	std::cout << "|Dog| destructor called\n" << std::flush;
}

std::string Dog::getType() const{
	return this->type;
}

void Dog::makeSound() const {
	std::cout << "whouaf\n" << std::flush;
}