/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:41:59 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 18:27:49 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	this->name = name;
}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon &w){
	this->weapon = &w;
}

void HumanB::attack(){
	if (this->weapon == NULL)
	{
		std::cout << this->name << " attacks with nothing\n" << std::flush; 	
	}
	else {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << "\n" << std::flush;
	}
}
