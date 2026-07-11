/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:08:55 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 16:04:37 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){
	ClapTrap clap;
	clap.takeDamage(9);
	clap.attack(std::string("somebody"));
	clap.beRepaired(9);
	clap.attack(std::string("somebody"));
	clap.takeDamage(10);
	clap.attack(std::string("somebody"));
}