/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:55:09 by tseche            #+#    #+#             */
/*   Updated: 2026/07/03 13:20:09 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>


int main(){
	std::vector<int> a = {1, 2, 3, 4, 5};
	int search = 3;
	int res = easyfind(a, search);
	if (res != __INT32_MAX__)
		std::cout << "find: [" << res << "]\n" << std::flush;
	else
		std::cout << "not find\n" << std::flush;

	search = 12;
	res = easyfind(a, search);
	if (res != __INT32_MAX__)
		std::cout << "find: [" << res << "]\n" << std::flush;
	else
		std::cout << "not find\n" << std::flush;
}
