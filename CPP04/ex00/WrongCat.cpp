/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:11:42 by tseche            #+#    #+#             */
/*   Updated: 2026/04/27 16:12:12 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat(){
	std::cout << "|WrongCat| default constructor called\n" << std::flush;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &WrongCat){
	std::cout << "|WrongCat| default constructor called\n" << std::flush;
	if (this != &WrongCat)
		*this = WrongCat;
}

WrongCat &WrongCat::operator=(WrongCat &WrongCat){
	if (this != &WrongCat)
		*this = WrongCat;
	return (WrongCat);
}

WrongCat::~WrongCat(){
	std::cout << "|WrongCat| destructor called\n" << std::flush;
}

std::string WrongCat::getType() const{
	return this->type;
}

void WrongCat::makeSound() const{
	std::cout << "<cat sound> but it seems kinda wrong\n" << std::flush;
}