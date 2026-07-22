/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:29:15 by tseche            #+#    #+#             */
/*   Updated: 2026/07/14 19:29:58 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	protected:
		std::string type;
	public:
		WrongCat();
		WrongCat(WrongCat &cat);
		~WrongCat();

		WrongCat &operator=(WrongCat &cat);
		std::string getType() const;
		void makeSound() const;
};