/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:01:46 by tseche          #+#    #+#             */
/*   Updated: 2026/07/01 18:18:40 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main()
{
	std::cout << YELLOW << "Test 1 : default constructor" << RESET << std::endl;
	{
		Array<int> a;
		std::cout << "size = " << a.size() << std::endl;
	}

	std::cout << std::endl;

	std::cout << YELLOW << "Test 2 : sized constructor + operator[]" << RESET << std::endl;
	{
		Array<int> a(5);
		std::cout << "size = " << a.size() << std::endl;

		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i * 10;

		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
	}

	std::cout << std::endl;

	std::cout << YELLOW << "Test 3 : copy constructor" << RESET << std::endl;
	{
		Array<int> a(3);
		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i + 1;

		Array<int> b(a);
		std::cout << "b.size = " << b.size() << std::endl;
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << "b[" << i << "] = " << b[i] << std::endl;
	}

	std::cout << std::endl;

	std::cout << YELLOW << "Test 4 : assignment operator" << RESET << std::endl;
	{
		Array<int> a(2);
		a[0] = 100;
		a[1] = 200;

		Array<int> b;
		b = a;

		std::cout << "b.size = " << b.size() << std::endl;
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << "b[" << i << "] = " << b[i] << std::endl;
	}

	std::cout << std::endl;

	std::cout << YELLOW << "Test 5 : out of bounds access" << RESET << std::endl;
	{
		Array<int> a(3);

		try
		{
			a[42];
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	return 0;
}