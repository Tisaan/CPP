/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:19:50 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 15:20:13 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

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