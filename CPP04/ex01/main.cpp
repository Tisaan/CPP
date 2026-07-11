/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:22:34 by tseche            #+#    #+#             */
/*   Updated: 2026/07/11 16:48:51 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	
	Animal *arr[10];
	for (int i = 0; i < 10; i++){
		if (i < 5)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}

	Cat Kitty = Cat();
	Kitty.getbrain()->ideas[0] = "un truc";
	
	Cat copy = Kitty;

	Kitty.getbrain()->ideas[0] = "une chose";

	std::cout << Kitty.getbrain()->ideas[0] << std::endl;
	std::cout << copy.getbrain()->ideas[0] << std::endl;

	for (size_t i = 0; i < 10; i++){
		delete arr[i];
	}
	return 0;
}