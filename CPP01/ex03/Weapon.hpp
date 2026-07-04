/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:27:02 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 17:52:11 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon{
	private :
		std::string type;
	public:
		const std::string &getType() const;
		void setType(std::string);
		Weapon(std::string name);
		~Weapon();
};