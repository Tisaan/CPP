/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:19:25 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 15:19:39 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog: public Animal{
	protected:
		std::string type;
	public:
		Dog();
		Dog(Dog &Dog);
		~Dog();

		Dog &operator=(Dog &dog);
		std::string getType() const;
		void makeSound() const;
};