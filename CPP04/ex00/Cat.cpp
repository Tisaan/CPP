/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:22:01 by tseche            #+#    #+#             */
/*   Updated: 2026/07/04 14:04:52 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Cat::Cat(): Animal(){
	std::cout << "|Cat| default constructor called\n" << std::flush;
	this->type = "Cat";
}

Cat::Cat(Cat &Cat): Animal() {
	std::cout << "|Cat| default constructor called\n" << std::flush;
	if (this != &Cat)
		*this = Cat;
}

Cat &Cat::operator=(Cat &Cat){
	if (this != &Cat)
		*this = Cat;
	return (Cat);
}

Cat::~Cat(){
	std::cout << "|Cat| destructor called\n" << std::flush;
}

std::string Cat::getType() const{
	return this->type;
}

void Cat::makeSound() const{
	std::cout << "miaou\n" << std::flush;
}