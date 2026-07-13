/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:08:55 by tseche            #+#    #+#             */
/*   Updated: 2026/07/13 21:38:00 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){
	ClapTrap clap;
	ClapTrap c = clap;
	clap.takeDamage(9);
	clap.attack(std::string("somebody"));
	clap.beRepaired(9);
	clap.attack(std::string("somebody"));
	clap.takeDamage(10);
	clap.attack(std::string("somebody"));
}