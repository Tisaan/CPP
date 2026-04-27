/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:16:42 by tseche            #+#    #+#             */
/*   Updated: 2026/04/22 16:35:57 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap{
	private:
		std::string name;
		int hit;
		int energy;
		int attack_d;
	public:
		ScavTrap();
		ScavTrap(std::string &name);
		ScavTrap(ScavTrap &clap);
		~ScavTrap();

		ScavTrap &operator=(ScavTrap &clap);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void guardgate();
};