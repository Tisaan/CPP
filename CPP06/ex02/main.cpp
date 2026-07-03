/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:15:23 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/30 16:10:28 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main(){
	std::srand(std::time(NULL));

	for (int i = 0; i < 6; i++)
	{
		Base* p = generate();

		identify(p);
		identify(*p);

		delete p;
	}

	return 0;
}