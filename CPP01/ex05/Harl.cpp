/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:46:08 by tseche            #+#    #+#             */
/*   Updated: 2026/07/04 16:45:13 by tseche           ###   ########.fr       */
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
	struct MethodInfo {
		std::string name;
		void (Harl::*method)();
	};
	
	static const MethodInfo methods[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};
	for (int i = 0; i < 4; i++)
	{
		if (level == methods[i].name)
			(this->*methods[i].method)();
	}
}
