/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:08:32 by tseche            #+#    #+#             */
/*   Updated: 2026/07/01 14:12:11 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.hpp"
#include <iostream>

int main(){

	int a = 0;
	int b = 1;
	std::cout << "Max: " << max(a, b) << "\n" << std::flush;
	std::cout << "Min: " << min(a, b) << "\n" << std::flush;
	std::cout << "before swap: {a :" << a << ", b:" << b << "}\n" << std::flush;
	swap(a, b);
	std::cout << "after swap: {a :" << a << ", b:" << b << "}\n" << std::flush;
}