/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:33:00 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 15:49:00 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie{
	private:
		std::string name;
	public:
		void annonce();
		Zombie(std::string);
		~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
