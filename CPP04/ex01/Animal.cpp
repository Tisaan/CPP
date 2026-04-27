/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:48:30 by tseche            #+#    #+#             */
/*   Updated: 2026/04/27 17:42:37 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	std::cout << "|Animal| default constructor called\n" << std::flush;
	this->type = "animal";
}

Animal::Animal(const Animal &animal){
	std::cout << "|Animal| copy constructor called\n" << std::flush;
	if (this != &animal)
		*this = animal;
}

const Animal &Animal::operator=(const Animal &animal){
	if (this != &animal)
		*this = animal;
	return animal;
}

std::string Animal::getType() const{
	return this->type;
}

void Animal::makeSound() const{
	std::cout << "idk\n" << std::flush;
}

Animal::~Animal(){std::cout << "|Animal| destructor called\n" << std::flush;}

