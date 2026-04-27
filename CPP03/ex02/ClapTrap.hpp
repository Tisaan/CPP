/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:09:15 by tseche            #+#    #+#             */
/*   Updated: 2026/04/22 15:22:24 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap{
	private:
		std::string name;
		int hit;
		int energy;
		int attack_d;
	public:
		ClapTrap();
		ClapTrap(std::string &name);
		ClapTrap(ClapTrap &clap);
		~ClapTrap();

		ClapTrap &operator=(ClapTrap &clap);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};