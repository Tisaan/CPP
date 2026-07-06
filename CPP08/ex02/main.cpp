/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 18:09:44 by tseche            #+#    #+#             */
/*   Updated: 2026/07/06 13:49:17 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top:" << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size:" << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::deque<int>::iterator it = mstack.begin();
    std::deque<int>::iterator ite = mstack.end();
	size_t last = 0;
    std::cout << "size:" << mstack.size() << std::endl;
	std::string dec = std::string("-");
    for (; it != ite; ++it) {
		size_t lenght = std::floor(std::log10(*it));
		if (*it != 0)
		{
			for (size_t i = 0; i < lenght + 2; i++)
			{
				//std::cout << "ch\n" << std::flush;
				dec.append("-");
			}
		}
		else {
			for (size_t i = 0; i < last + 2; i++)
			{
				//std::cout << "ch\n" << std::flush;
				dec.append("-");
			}
		}
		std::cout << dec << "\n" << std::flush;
        std::cout << "|" << *it << "|\n" << std::flush;
		last = lenght;
    }
	std::cout << dec << "\n" << std::flush;
    return 0;
}