/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:42:09 by tseche            #+#    #+#             */
/*   Updated: 2026/04/27 17:44:30 by tseche           ###   ########.fr       */
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


class Cat: public Animal{
	protected:
		std::string type;
		Brain *b;
	public:
		Cat();
		Cat(const Cat &cat);
		~Cat();

		const Cat &operator=(const Cat &cat);
		std::string getType() const;
		void makeSound() const;
};