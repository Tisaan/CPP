/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:08:00 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 15:08:14 by tseche           ###   ########.fr       */
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

		const Dog &operator=(const Dog &dog);
		std::string getType() const;
		void makeSound() const;
};