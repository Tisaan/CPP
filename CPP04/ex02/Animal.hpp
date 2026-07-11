/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:42:09 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 15:07:21 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include "Brains.hpp"


class Animal{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &animal);
		virtual ~Animal();

		const Animal &operator=(const Animal &animal);
		virtual std::string getType() const = 0;
		virtual void makeSound() const;
};



