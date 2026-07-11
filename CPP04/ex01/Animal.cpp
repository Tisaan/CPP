/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:48:30 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 16:47:39 by tseche           ###   ########.fr       */
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
		this->type = animal.getType();
}

Animal &Animal::operator=(const Animal &animal){

	std::cout << "|Animal| copy assignment constructor called\n" << std::flush;
	if (this != &animal)
		this->type = animal.getType();
	return (*this);
}

inline std::string Animal::getType() const{
	return this->type;
}

void Animal::makeSound() const{
	std::cout << "idk\n" << std::flush;
}

Animal::~Animal(){std::cout << "|Animal| destructor called\n" << std::flush;}

