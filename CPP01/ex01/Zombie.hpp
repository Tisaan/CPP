/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:33:00 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 16:55:28 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie{
	public:
		std::string _name;
	public:
		void annonce();
		Zombie();
		~Zombie();
		void setName(std::string name);
};

Zombie *zombieHorde(int n, std::string name);
