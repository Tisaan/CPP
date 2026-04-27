/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:22:34 by tseche            #+#    #+#             */
/*   Updated: 2026/04/27 17:23:05 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

int main()
{
	
	Animal *arr[100];
	for (int i = 0; i < 100; i++){
		if (i < 50)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}

	for (Animal *an: arr){
		delete an;
	}
	return 0;
}