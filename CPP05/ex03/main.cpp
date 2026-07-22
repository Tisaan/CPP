/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:20:13 by rcompain          #+#    #+#             */
/*   Updated: 2026/07/15 15:28:25 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main( void )
{
	srand(time(NULL));
	// Test 1 : Intern creates a ShrubberyCreationForm
	std::cout << YELLOW << "Test 1 : Intern creates ShrubberyCreationForm" << RESET << std::endl;
	{
		Intern intern;
		AForm* form = intern.makeForm("ShrubberyCreationForm", "ShrubberyCreationForm");

		Bureaucrat a("A", 1);
		a.signForm(*form);
		a.executeForm(*form);
		delete form;
	}

	std::cout << std::endl;

	// Test 2 : Intern creates a RobotomyRequestForm
	std::cout << YELLOW << "Test 2 : Intern creates RobotomyRequestForm" << RESET << std::endl;
	{
		Intern intern;
		AForm* form = intern.makeForm("RobotomyRequestForm", "RobotomyRequestForm");

		Bureaucrat a("A", 1);
		a.signForm(*form);
		a.executeForm(*form);
		a.executeForm(*form);
		delete form;
	}

	std::cout << std::endl;

	// Test 3 : Intern creates a PresidentialPardonForm
	std::cout << YELLOW << "Test 3 : Intern creates PresidentialPardonForm" << RESET << std::endl;
	{
		Intern intern;
		AForm* form = intern.makeForm("PresidentialPardonForm", "PresidentialPardonForm");

		Bureaucrat a("A", 1);
		a.signForm(*form);
		a.executeForm(*form);
		delete form;
	}

	std::cout << std::endl;

	// Test 4 : Intern gets an unknown form name
	std::cout << YELLOW << "Test 4 : Intern unknown form" << RESET << std::endl;
	{
		Intern intern;
		AForm* form = intern.makeForm("UnknownForm", "target");

		if (form)
			delete form;
	}

	return 0;
}