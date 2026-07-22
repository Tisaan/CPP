/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:22:34 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 15:02:06 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define  ARRAY_SIZE 10

int main()
{
	
	Animal *arr[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++){
		if (i < (ARRAY_SIZE / 2))
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}

	Cat Kitty = Cat();
	Kitty.getbrain()->ideas[0] = "une idee";
	
	Cat copy = Kitty;

	Kitty.getbrain()->ideas[0] = "une autre idee";

	std::cout << copy.getbrain()->ideas[0] << std::endl;
	std::cout << Kitty.getbrain()->ideas[0] << std::endl;

	for (size_t i = 0; i < ARRAY_SIZE; i++){
		delete arr[i];
	}
	return 0;
}