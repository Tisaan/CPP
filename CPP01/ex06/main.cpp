/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:45:51 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 20:16:59 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av){
	if (ac != 2)
	{
		std::cout << "Harl [level {DEBUG, INFO, WARNING, ERROR}]\n" << std::flush;
		return 1;
	}
	Harl h = Harl();
	h.complain(av[1]);
}