/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:08:55 by tseche            #+#    #+#             */
/*   Updated: 2026/07/13 21:36:15 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(){
	FragTrap frag;
	ClapTrap c = frag;
	frag.takeDamage(10);
	frag.attack(std::string("somebody"));
	frag.beRepaired(10);
	frag.attack(std::string("somebody"));
	frag.highFivesGuys();
}