/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:34:19 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 17:46:17 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &w){
	this->weapon = &w;
	this->name = name;
};

void HumanA::attack(){
	std::cout << this->name << " attacks with their " << this->weapon->getType() << "\n" << std::flush;
}

HumanA::~HumanA(){}