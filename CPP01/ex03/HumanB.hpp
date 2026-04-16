/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:33:39 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 20:07:02 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "weapon.hpp"

class HumanB{
	private:
		Weapon *weapon;
		std::string name;
	public:
		void attack();
		void setWeapon(Weapon &w);
		HumanB(std::string name);
		~HumanB();
};