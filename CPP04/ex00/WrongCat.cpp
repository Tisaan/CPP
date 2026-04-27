/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongwrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:11:42 by tseche            #+#    #+#             */
/*   Updated: 2026/04/27 16:12:12 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

wrongCat::wrongCat(){
	std::cout << "|wrongCat| default constructor called\n" << std::flush;
	this->type = "wrongCat";
}

wrongCat::wrongCat(wrongCat &wrongCat){
	std::cout << "|wrongCat| default constructor called\n" << std::flush;
	if (this != &wrongCat)
		*this = wrongCat;
}

wrongCat &wrongCat::operator=(wrongCat &wrongCat){
	if (this != &wrongCat)
		*this = wrongCat;
	return (wrongCat);
}

wrongCat::~wrongCat(){
	std::cout << "|wrongCat| destructor called\n" << std::flush;
}

std::string wrongCat::getType() const{
	return this->type;
}

void wrongCat::makeSound() const{
	std::cout << "<cat sound> but it seems kinda wrong\n" << std::flush;
}