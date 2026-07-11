/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:08:55 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 16:09:08 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(){
	ScavTrap scav;
	scav.takeDamage(10);
	scav.attack(std::string("somebody"));
	scav.beRepaired(10);
	scav.attack(std::string("somebody"));
	scav.guardGate();
}