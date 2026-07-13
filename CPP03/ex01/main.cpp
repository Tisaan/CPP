/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:08:55 by tseche            #+#    #+#             */
/*   Updated: 2026/07/13 21:38:22 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(){
	ScavTrap scav;
	ClapTrap c = scav;
	scav.takeDamage(10);
	scav.attack(std::string("somebody"));
	scav.beRepaired(10);
	scav.attack(std::string("somebody"));
	scav.guardGate();
}