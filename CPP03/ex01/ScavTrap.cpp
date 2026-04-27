/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:16:51 by tseche            #+#    #+#             */
/*   Updated: 2026/04/22 16:46:01 by tseche           ###   ########.fr       */
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

ScavTrap::ScavTrap(ScavTrap &scav): ClapTrap(){
	std::cout << "|Scavtrap| copy constuctor called\n" << std::flush;
	if (this != &scav)
		*this = scav;
}

ScavTrap &ScavTrap::operator=(ScavTrap &scav){
	if (this != &scav)
		*this = scav;
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "|Scavtrap| destructor called\n" << std::flush;
}

void ScavTrap::attack(const std::string &target){
	if (this->energy == 0 || this->hit == 0){
		std::cout << "|ScavTrap| couldn't do anything, no energy/hit point left\n" << std::flush;
		return;
	}
	this->energy -= 1;
	std::cout << "|ScavTrap| " << this->name << "attacks " << target << ", causing " << this->attack_d << " points of damage!\n" << std::flush;
	
}

void ScavTrap::beRepaired(unsigned int amount){
	if (this->energy == 0){
		std::cout << "|ScavTrap| couldn't abything, no energy/hit point left\n" << std::flush;
		return;
	}
	std::cout << "|ScavTrap| " << this->name << "gain " << amount << " hit point\n" << std::flush;
	this->hit += amount;
	this->energy -= 1;
}

void ScavTrap::takeDamage(unsigned int amount){
	if (this->hit == 0){
		std::cout << "|ScavTrap| " << this->name << " is already dead.\n" << std::flush;
		return;
	}
	std::cout << "|ScavTrap| " << this->name << "take " << amount << " damage\n" << std::flush;
	this->hit -= amount;
}

void ScavTrap::guardgate(){
	std::cout << "|Scavtrap|" << this->name <<"is in guard keeper mode\n" << std::flush;
}