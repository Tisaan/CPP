/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:09:23 by tseche            #+#    #+#             */
/*   Updated: 2026/04/22 16:45:17 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "|ClapTrap| default constructor called\n" << std::flush;
	this->name = std::string("george");
	this->energy = 10;
	this->hit = 10;
	this->attack_d = 10;
}

ClapTrap::ClapTrap(ClapTrap &clap){
	std::cout << "|ClapTrap| copy constructor called\n" << std::flush;
	*this = clap;
}

ClapTrap::ClapTrap(std::string &name){
	std::cout << "|ClapTrap| naming constructor called\n" << std::flush;
	this->name = name;
	this->energy = 10;
	this->hit = 10;
	this->attack_d = 10;
}

ClapTrap &ClapTrap::operator=(ClapTrap &clap) {
	if (this != &clap)
		*this = clap;
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "|ClapTrap| destructor called\n" << std::flush;
}

//

void ClapTrap::attack(const std::string &target){
	if (this->energy == 0 || this->hit == 0){
		std::cout << "|ClapTrap| couldn't do anything, no energy/hit point left\n" << std::flush;
		return;
	}
	this->energy -= 1;
	std::cout << "|Claptrap| " << this->name << " attacks " << target << ", causing " << this->attack_d << " points of damage!\n" << std::flush;
	
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->energy == 0){
		std::cout << "|ClapTrap| couldn't abything, no energy/hit point left\n" << std::flush;
		return;
	}
	std::cout << "|Claptrap| " << this->name << " gain " << amount << " hit point\n" << std::flush;
	this->hit += amount;
	this->energy -= 1;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->hit == 0){
		std::cout << "|Claptrap| " << this->name << " is already dead.\n" << std::flush;
		return;
	}
	std::cout << "|Claptrap| " << this->name << " take " << amount << " damage\n" << std::flush;
	this->hit -= amount;
}



