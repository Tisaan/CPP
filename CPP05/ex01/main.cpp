/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:20:13 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/24 12:55:04 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main( void )
{
	// Test 1 : valid Form construction and display
	std::cout << YELLOW << "Test 1 : valid Form construction and display" << RESET << std::endl;
	{
		Form form("Tax declaration", 50, 100);

		std::cout << form << std::endl;
	}

	std::cout << std::endl;

	// Test 2 : Form constructed with a grade too high (< 1)
	std::cout << YELLOW << "Test 2 : Form grade too high" << RESET << std::endl;
	{
		try
		{
			Form form("Invalid form", 0, 50);
			std::cout << form << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	// Test 3 : Form constructed with a grade too low (> 150)
	std::cout << YELLOW << "Test 3 : Form grade too low" << RESET << std::endl;
	{
		try
		{
			Form form("Invalid form", 50, 200);
			std::cout << form << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	// Test 4 : beSigned with a sufficient grade
	std::cout << YELLOW << "Test 4 : beSigned with a sufficient grade" << RESET << std::endl;
	{
		Bureaucrat boss("Boss", 10);
		Form form("Vacation request", 50, 100);

		form.beSigned(boss);
		std::cout << form << std::endl;
	}

	std::cout << std::endl;

	// Test 5 : beSigned with an insufficient grade
	std::cout << YELLOW << "Test 5 : beSigned with an insufficient grade" << RESET << std::endl;
	{
		Bureaucrat intern("Intern", 100);
		Form form("Confidential report", 10, 50);

		try
		{
			form.beSigned(intern);
		}
		catch (std::exception& e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
		std::cout << form << std::endl;
	}

	std::cout << std::endl;

	// Test 6 : Bureaucrat::signForm succeeds
	std::cout << YELLOW << "Test 6 : signForm succeeds" << RESET << std::endl;
	{
		Bureaucrat director("Director", 1);
		Form form("Budget approval", 5, 50);

		director.signForm(form);
		std::cout << form << std::endl;
	}

	std::cout << std::endl;

	// Test 7 : Bureaucrat::signForm fails
	std::cout << YELLOW << "Test 7 : signForm fails" << RESET << std::endl;
	{
		Bureaucrat junior("Junior", 130);
		Form form("Top secret memo", 5, 50);

		junior.signForm(form);
		std::cout << form << std::endl;
	}

	std::cout << std::endl;

	// Test 8 : Form copy constructor and assignment operator
	std::cout << YELLOW << "Test 8 : Form copy constructor and assignment operator" << RESET << std::endl;
	{
		Bureaucrat boss("Boss", 10);
		Form original("Original form", 50, 100);

		original.beSigned(boss);

		Form copy(original);
		Form assigned("Placeholder", 1, 1);
		assigned = original;

		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
		std::cout << "Assigned: " << assigned << std::endl;
	}

	return 0;
}