/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:16:51 by tseche            #+#    #+#             */
/*   Updated: 2026/07/13 21:20:34 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
	std::cout << "|Scavtrap| default constuctor called\n" << std::flush;
	this->attack_d = 20;
	this->hit = 100;
	this->energy = 50;
}

ScavTrap::ScavTrap(const ScavTrap &scav): ClapTrap(){
	std::cout << "|Scavtrap| copy constuctor called\n" << std::flush;
	if (this != &scav)
		*this = scav;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(){
	std::cout << "|Scavtrap| string constuctor called\n" << std::flush;
	this->name = name;
	this->attack_d = 20;
	this->hit = 100;
	this->energy = 50;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scav){
	if (this != &scav)
	{
		this->name = scav.name;
		this->energy = scav.energy;
		this->hit = scav.hit;
		this->attack_d = scav.attack_d;
	}
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "|Scavtrap| destructor called\n" << std::flush;
}


void ScavTrap::attack(const std::string &target){
	if (this->energy == 0 || this->hit <= 0){
		std::cout << "|ScavTrap| couldn't do anything, no energy/hit point left\n" << std::flush;
		return;
	}
	this->energy -= 1;
	std::cout << "|Scavtrap| " << this->name << " attacks " << target << ", causing " << this->attack_d << " points of damage!\n" << std::flush;
	
}

void ScavTrap::guardGate(){
	std::cout << "|Scavtrap|" << this->name <<"is in guard keeper mode\n" << std::flush;
}