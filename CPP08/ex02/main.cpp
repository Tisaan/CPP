/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 18:09:44 by tseche            #+#    #+#             */
/*   Updated: 2026/07/19 14:28:12 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "MutantStack.hpp"
#include <list>

int main() {
	std::cout << "MutantStack\n" << std::flush;
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


	std::cout << "List\n" << std::flush;
	std::list<int> lstack;
	lstack.push_back(5);
	lstack.push_back(17);
	std::cout << "top: "<< lstack.back() << std::endl;
	lstack.pop_back();
	std::cout << "size: " << lstack.size() << std::endl;
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	lstack.push_back(0);
	std::list<int>::iterator lit = lstack.begin();
	std::list<int>::iterator lite = lstack.end();
	++lit;
	--lit;
	std::cout << "size: " << lstack.size() << std::endl;
	while (lit != lite)
	{
	std::cout << *lit << std::endl;
		++lit;
	}
    return 0;
}