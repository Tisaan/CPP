/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongwrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:31:48 by tseche            #+#    #+#             */
/*   Updated: 2026/04/27 16:02:44 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class wrongAnimal{
	protected:
		std::string type;
	public:
		wrongAnimal();
		wrongAnimal(wrongAnimal &wrongAnimal);
		~wrongAnimal();

		wrongAnimal &operator=(wrongAnimal &wrongAnimal);
		virtual std::string getType() const;
		virtual void makeSound() const;
};

class wrongCat: public wrongAnimal{
	protected:
		std::string type;
	public:
		wrongCat();
		wrongCat(wrongCat &cat);
		~wrongCat();

		wrongCat &operator=(wrongCat &cat);
		std::string getType() const;
		void makeSound() const;
};
