/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:16:51 by tseche            #+#    #+#             */
/*   Updated: 2026/04/25 15:18:19 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
	std::cout << "|FragTrap| default constuctor called\n" << std::flush;
	this->attack_d = 30;
	this->hit = 100;
	this->energy = 100;
}

FragTrap::FragTrap(FragTrap &scav): ClapTrap(){
	std::cout << "|FragTrap| copy constuctor called\n" << std::flush;
	if (this != &scav)
		*this = scav;
}

FragTrap &FragTrap::operator=(FragTrap &scav){
	if (this != &scav)
		*this = scav;
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "|FragTrap| destructor called\n" << std::flush;
}

void FragTrap::attack(const std::string &target){
	if (this->energy == 0 || this->hit == 0){
		std::cout << "|FragTrap| couldn't do anything, no energy/hit point left\n" << std::flush;
		return;
	}
	this->energy -= 1;
	std::cout << "|FragTrap| " << this->name << "attacks " << target << ", causing " << this->attack_d << " points of damage!\n" << std::flush;
	
}

void FragTrap::beRepaired(unsigned int amount){
	if (this->energy == 0){
		std::cout << "|FragTrap| couldn't abything, no energy/hit point left\n" << std::flush;
		return;
	}
	std::cout << "|FragTrap| " << this->name << "gain " << amount << " hit point\n" << std::flush;
	this->hit += amount;
	this->energy -= 1;
}

void FragTrap::takeDamage(unsigned int amount){
	if (this->hit == 0){
		std::cout << "|FragTrap| " << this->name << " is already dead.\n" << std::flush;
		return;
	}
	std::cout << "|FragTrap| " << this->name << "take " << amount << " damage\n" << std::flush;
	this->hit -= amount;
}

void FragTrap::highFivesGuys(){
	std::cout << "|FragTrap| High-Five guys?";
}