/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:59:38 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 16:58:12 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name)
{
	if (n <= 0)
	{
		std::cout << "Illegal number input\n" << std::flush;
		return (NULL);
	}
	Zombie *z = new Zombie[n];
	if (!z)
		return (NULL);
	for (int i = 0; i < n; i++)
		z[i].setName(name);
	return (z);	
}