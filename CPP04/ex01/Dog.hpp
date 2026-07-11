/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:35:26 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 16:31:31 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog: public Animal{
	protected:
		std::string type;
		Brain *b;
	public:
		Dog();
		Dog(const Dog &Dog);
		~Dog();

		Dog &operator=(const Dog &dog);
		std::string getType() const;
		void makeSound() const;
};
