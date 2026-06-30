/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:22:07 by tseche            #+#    #+#             */
/*   Updated: 2026/06/29 15:04:53 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

int	main(int ac, char **argv)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; argv[i]; i++)
	{
		std::string s = std::string(argv[i]);
		for (std::string::iterator j = s.begin(); j < s.end(); j++)
		{
			std::cout << static_cast<unsigned char>(std::toupper(*j));
		}
	}
	std::cout << std::endl;
	return (1);
}