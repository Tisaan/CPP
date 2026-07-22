/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:55:09 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 16:47:08 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>


int main(){
	std::vector<int> a = std::vector<int>();
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	int search = 3;
	int res = easyfind(a, search);
	if (res != INT_MAX)
		std::cout << "find: [" << res << "]\n" << std::flush;
	else
		std::cout << "not find\n" << std::flush;

	search = 12;
	res = easyfind(a, search);
	if (res != INT_MAX)
		std::cout << "find: [" << res << "]\n" << std::flush;
	else
		std::cout << "not find\n" << std::flush;
}
