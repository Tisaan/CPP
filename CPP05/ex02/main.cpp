/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:20:13 by tseche          #+#    #+#             */
/*   Updated: 2026/07/15 15:21:48 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main( void )
{

	srand(time(NULL));
	// Test 1 : execute without signing first
	std::cout << YELLOW << "Test 1 : execute unsigned form" << RESET << std::endl;
	{
		Bureaucrat 	a("A", 1);
		ShrubberyCreationForm form("ShrubberyCreation");

		a.executeForm(form);
	}

	std::cout << std::endl;

	// Test 2 : ShrubberyCreationForm - sign and execute successfully
	std::cout << YELLOW << "Test 2 : ShrubberyCreationForm success" << RESET << std::endl;
	{
		Bureaucrat a("A", 1);
		ShrubberyCreationForm form("ShrubberyCreation");

		a.signForm(form);
		a.executeForm(form);
	}

	std::cout << std::endl;

	// Test 3 : ShrubberyCreationForm - grade too low to execute
	std::cout << YELLOW << "Test 3 : ShrubberyCreationForm grade too low to execute" << RESET << std::endl;
	{
		Bureaucrat a("A", 145);
		Bureaucrat b("B", 138);
		ShrubberyCreationForm form("ShrubberyCreation");

		a.signForm(form);
		b.executeForm(form);
	}

	std::cout << std::endl;

	// Test 4 : RobotomyRequestForm - sign and execute (50/50)
	std::cout << YELLOW << "Test 4 : RobotomyRequestForm success (random)" << RESET << std::endl;
	{
		Bureaucrat a("A", 1);
		RobotomyRequestForm form("RobotomyRequest");

		a.signForm(form);
		a.executeForm(form);
		a.executeForm(form);
		a.executeForm(form);
	}

	std::cout << std::endl;

	// Test 5 : RobotomyRequestForm - grade too low to sign
	std::cout << YELLOW << "Test 5 : RobotomyRequestForm grade too low to sign" << RESET << std::endl;
	{
		Bureaucrat a("A", 100);
		RobotomyRequestForm form("RobotomyRequest");

		a.signForm(form);
		a.executeForm(form);
	}

	std::cout << std::endl;

	// Test 6 : PresidentialPardonForm - sign and execute successfully
	std::cout << YELLOW << "Test 6 : PresidentialPardonForm success" << RESET << std::endl;
	{
		Bureaucrat a("A", 1);
		PresidentialPardonForm form("PresidentialPardon");

		a.signForm(form);
		a.executeForm(form);
	}

	std::cout << std::endl;

	// Test 7 : PresidentialPardonForm - grade too low to execute
	std::cout << YELLOW << "Test 7 : PresidentialPardonForm grade too low to execute" << RESET << std::endl;
	{
		Bureaucrat a("A", 1);
		Bureaucrat b("B", 10);
		PresidentialPardonForm form("PresidentialPardon");

		a.signForm(form);
		b.executeForm(form);
	}

	return 0;
}