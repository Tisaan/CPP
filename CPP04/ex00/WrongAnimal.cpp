/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:48:30 by tseche            #+#    #+#             */
/*   Updated: 2026/04/27 16:10:23 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

wrongAnimal::wrongAnimal(){
	std::cout << "|wrongAnimal| default constructor called\n" << std::flush;
	this->type = "wrongAnimal";
}

wrongAnimal::wrongAnimal(wrongAnimal &wrongAnimal){
	std::cout << "|wrongAnimal| copy constructor called\n" << std::flush;
	if (this != &wrongAnimal)
		*this = wrongAnimal;
}

wrongAnimal &wrongAnimal::operator=(wrongAnimal &wrongAnimal){
	if (this != &wrongAnimal)
		*this = wrongAnimal;
	return wrongAnimal;
}

std::string wrongAnimal::getType() const{
	return this->type;
}

void wrongAnimal::makeSound() const{
	std::cout << "idk but it's the wrong one\n" << std::flush;
}

wrongAnimal::~wrongAnimal(){std::cout << "|wrongAnimal| destructor called\n" << std::flush;}

