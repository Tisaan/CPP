/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:48:30 by tseche            #+#    #+#             */
/*   Updated: 2026/07/14 19:32:46 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "|WrongAnimal| default constructor called\n" << std::flush;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal &WrongAnimal){
	std::cout << "|WrongAnimal| copy constructor called\n" << std::flush;
	if (this != &WrongAnimal)
		*this = WrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &WrongAnimal){
	if (this != &WrongAnimal)
		*this = WrongAnimal;
	return WrongAnimal;
}

std::string WrongAnimal::getType() const{
	return this->type;
}

void WrongAnimal::makeSound() const{
	std::cout << "idk but it's the wrong one\n" << std::flush;
}

WrongAnimal::~WrongAnimal(){std::cout << "|WrongAnimal| destructor called\n" << std::flush;}

