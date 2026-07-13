/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:16:51 by tseche            #+#    #+#             */
/*   Updated: 2026/07/13 21:22:12 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
	std::cout << "|FragTrap| default constuctor called\n" << std::flush;
	this->attack_d = 30;
	this->hit = 100;
	this->energy = 100;
}

FragTrap::FragTrap(const FragTrap &scav): ClapTrap(){
	std::cout << "|FragTrap| copy constuctor called\n" << std::flush;
	if (this != &scav)
		*this = scav;
}

FragTrap::FragTrap(const std::string &s){
	std::cout << "|Scavtrap| naming constructor called\n" << std::flush;
	this->name = s;
	this->energy = 100;
	this->hit = 30;
	this->attack_d = 100;
}

FragTrap &FragTrap::operator=(const FragTrap &scav){
	if (this != &scav)
	{
		this->name = scav.name;
		this->energy = scav.energy;
		this->hit = scav.hit;
		this->attack_d = scav.attack_d;
	}
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "|FragTrap| destructor called\n" << std::flush;
}

void FragTrap::highFivesGuys(){
	std::cout << "|FragTrap| High-Five guys?\n" << std::flush;
}