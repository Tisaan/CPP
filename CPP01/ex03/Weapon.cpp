/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:26:53 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 17:52:36 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.hpp"

Weapon::Weapon(std::string type){
	this->type = type;
}

Weapon::~Weapon(){}

const std::string &Weapon::getType() const {
	const std::string *type = &this->type;
	return *type;
}

void Weapon::setType(std::string name){
	this->type = name;
}