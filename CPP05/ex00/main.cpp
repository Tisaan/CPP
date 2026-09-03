/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:20:13 by tseche          #+#    #+#             */
/*   Updated: 2026/06/22 17:15:31 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main( void )
{
	// Test 1 : valid construction and operator<<
	std::cout << YELLOW << "Test 1 : valid construction and display" << RESET << std::endl;
	{
		Bureaucrat a("Alice", 1);
		Bureaucrat b("Bob", 42);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}

	std::cout << std::endl;

	// Test 2 : grade too low in constructor
	std::cout << YELLOW << "Test 2 : grade too low in constructor" << RESET << std::endl;
	{
		try
		{
			Bureaucrat c("Carl", 0);
			std::cout << c << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	// Test 3 : grade too high in constructor
	std::cout << YELLOW << "Test 3 : grade too high in constructor" << RESET << std::endl;
	{
		try
		{
			Bureaucrat d("Dave", 151);
			std::cout << d << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	// Test 4 : increaseGrade / decreaseGrade
	std::cout << YELLOW << "Test 4 : increase and decrease grade" << RESET << std::endl;
	{
		Bureaucrat e("Eve", 3);
		std::cout << e << std::endl;

		e.incr();
		std::cout << "After increaseGrade: " << e << std::endl;

		e.decr();
		e.decr();
		std::cout << "After decreaseGrade twice: " << e << std::endl;
	}

	std::cout << std::endl;

	// Test 5 : increaseGrade past the highest grade (1)
	std::cout << YELLOW << "Test 5 : increaseGrade past the highest grade" << RESET << std::endl;
	{
		Bureaucrat f("Frank", 1);
		try
		{
			f.incr();
		}
		catch (std::exception& e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	
	// Test 6 : decreaseGrade past the lowest grade (150)
	std::cout << YELLOW << "Test 6 : decreaseGrade past the lowest grade" << RESET << std::endl;
	{
		Bureaucrat g("Grace", 150);
		try
		{
			g.decr();
		}
		catch (std::exception& e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	// Test 7 : copy constructor and assignment operator
	std::cout << YELLOW << "Test 7 : copy constructor and assignment operator" << RESET << std::endl;
	{
		Bureaucrat h("Hank", 10);
		Bureaucrat copy(h);
		Bureaucrat assigned;

		assigned = h;

		std::cout << "Original: " << h << std::endl;
		std::cout << "Copy: " << copy << std::endl;
		std::cout << "Assigned: " << assigned << std::endl;
	}

	return 0;
}