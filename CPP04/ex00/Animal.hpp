/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:42:09 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 15:19:55 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

class Animal{
	protected:
		std::string type;
	public:
		Animal();
		Animal(Animal &animal);
		~Animal();

		Animal &operator=(Animal &animal);
		virtual std::string getType() const;
		virtual void makeSound() const;
};


