/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:35:53 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 16:41:32 by tseche           ###   ########.fr       */
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

		Cat &operator=(const Cat &cat);
		std::string getType() const;
		void makeSound() const;
		Brain *getbrain();
};