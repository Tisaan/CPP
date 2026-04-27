/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:22:01 by tseche            #+#    #+#             */
/*   Updated: 2026/04/27 17:43:19 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Cat::Cat(){
	std::cout << "|Cat| default constructor called\n" << std::flush;
	this->type = "Cat";
	this->b = new Brain();
}

Cat::Cat(const Cat &Cat){
	std::cout << "|Cat| default constructor called\n" << std::flush;
	if (this != &Cat)
		*this = Cat;
}

const Cat &Cat::operator=(const Cat &Cat){
	if (this != &Cat)
		*this = Cat;
	return (Cat);
}

Cat::~Cat(){
	std::cout << "|Cat| destructor called\n" << std::flush;
	delete this->b;
}

std::string Cat::getType() const{
	return this->type;
}

void Cat::makeSound() const{
	std::cout << "miaou\n" << std::flush;
}