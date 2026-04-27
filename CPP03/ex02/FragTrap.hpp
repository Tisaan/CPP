/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:45:17 by tseche            #+#    #+#             */
/*   Updated: 2026/04/22 17:46:49 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: ClapTrap{
	private:
		std::string name;
		int hit;
		int energy;
		int attack_d;
	public:
		FragTrap();
		FragTrap(std::string &name);
		FragTrap(FragTrap &clap);
		~FragTrap();

		FragTrap &operator=(FragTrap &clap);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void highFivesGuys(void);
};