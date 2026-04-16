/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:30:33 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 20:06:52 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "weapon.hpp"

class HumanA{
	private:
		Weapon *weapon;
		std::string name;
	public:
		void attack();	
		HumanA(const std::string &name, Weapon &w);
		~HumanA();
};