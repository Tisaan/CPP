/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:16:42 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 14:31:23 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &clap);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap &clap);

		void attack(const std::string &t);
		void guardGate();
};