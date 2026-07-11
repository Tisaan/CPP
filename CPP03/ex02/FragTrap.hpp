/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 17:45:17 by tseche            #+#    #+#             */
/*   Updated: 2026/07/08 16:08:36 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
	public:
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &clap);
		~FragTrap();

		FragTrap &operator=(const FragTrap &clap);

		void highFivesGuys(void);
};