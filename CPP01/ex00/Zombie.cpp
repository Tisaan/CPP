/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:35:59 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 15:57:22 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(){
	std::cout << "Destuctor called\n" << std::flush ;
}

void Zombie::annonce(){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n" << std::flush;
}



