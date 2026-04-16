/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:46:08 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 20:13:31 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){};

Harl::~Harl(){};

void Harl::debug(){
	std::cout << DEBUG << std::flush;
};

void Harl::info(){
	std::cout << INFO << std::flush;
};

void Harl::warning(){
	std::cout << WARNING << std::flush;
};

void Harl::error(){
	std::cout << ERROR << std::flush;
}

void Harl::complain(std::string level)
{
	static std::map<std::string, MethodPtr> methods;
	methods["DEBUG"] = &Harl::debug;
	methods["INFO"] = &Harl::info;
	methods["WARNING"] = &Harl::warning;
	methods["ERROR"] = &Harl::error;
	std::map<std::string, MethodPtr>::iterator it = methods.find(level);
	if (it != methods.end())
		(this->*(it->second))();
}
