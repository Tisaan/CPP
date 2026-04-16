/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:46:11 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 20:18:15 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>

#define DEBUG "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n"
#define INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"
#define WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n"
#define ERROR "This is unacceptable! I want to speak to the manager now.\n"

class Harl;

typedef void (Harl::*MethodPtr)();

class Harl{
	private:
		void debug();
		void info();
		void warning();
		void error();
	public:
		void complain(std::string level);
		Harl();
		~Harl();
};