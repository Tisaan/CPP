/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:22:01 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 16:48:00 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Cat.hpp"

Cat::Cat()
	: Animal(),
	  type("Cat"),
	  b(new Brain())
{
		std::cout << "|Cat| default constructor called\n" << std::flush;
}

Cat::Cat(const Cat &Cat): Animal(Cat) {
	std::cout << "|Cat| default constructor called\n" << std::flush;
	if (this != &Cat)
	{
		this->b = new Brain(*Cat.b);
		this->type = Cat.type;
	}
}


Cat &Cat::operator=(const Cat &Cat){
		std::cout << "|Cat| assignement constructor called\n" << std::flush;

	if (this != &Cat)
	{
		Animal::operator=(Cat);
		*this->b = *Cat.b;
	}
	return (*this);
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

Brain *Cat::getbrain(){
	return this->b;
}