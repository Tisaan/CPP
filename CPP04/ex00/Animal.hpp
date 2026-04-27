/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:42:09 by tseche            #+#    #+#             */
/*   Updated: 2026/04/27 16:21:33 by tseche           ###   ########.fr       */
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


class Cat: public Animal{
	protected:
		std::string type;
	public:
		Cat();
		Cat(Cat &cat);
		~Cat();

		Cat &operator=(Cat &cat);
		std::string getType() const;
		void makeSound() const;
};