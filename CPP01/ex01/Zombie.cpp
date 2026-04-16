/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:35:59 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 16:58:51 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
	_name = "default";
}

Zombie::~Zombie(){
}

void Zombie::setName(std::string name){
	this->_name = name;
}

void Zombie::annonce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}



