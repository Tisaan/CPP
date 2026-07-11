/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:07:32 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 15:07:51 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

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