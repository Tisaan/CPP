/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:23:00 by tseche            #+#    #+#             */
/*   Updated: 2026/06/25 13:53:55 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(){std::cout << "|Intern| default constructor called\n" << std::flush;};

Intern::Intern(const Intern &f)
{
	std::cout << "|Intern| copy constructor called\n" << std::flush;
	if (this != &f)
		*this = f;
}

Intern::Intern(const std::string &name, int grade, int exec){
	std::cout << "|Intern| argument constructor called\n" << std::flush;
}

Intern::~Intern(){std::cout << "|Intern| destructor called\n" << std::flush;}

const Intern &Intern::operator=(const Intern &s)
{
	std::cout << "|Intern| copy assignement constructor called\n" << std::flush;
	return *this;
}

AForm *Intern::makeForm(const std::string &n, const std::string &t){	
	if (n == "" || t == "")
	{
		std::cout << "You must a valid name/traget\n" << std::flush;
		return (NULL);
	}
	std::string f[3];
	f[0] = "PresidentialPardonForm";
	f[1] = "RobotomyRequestForm";
	f[2] = "ShrubberyCreationForm";
	int i = 0;
	for (std::string g = f[i]; i <= 2; i++, i <= 2 ? (g = f[i]): g)
	{
		if (g == n)
		{
			std::cout << "Intern creates " << n << "\n" << std::flush;
			switch (i){
				case 0 : return new PresidentialPardonForm(t);
				case 1: return new RobotomyRequestForm(t);
				case 2: return new ShrubberyCreationForm(t);
			}
		}
	}
	std::cout << "Couldn't create the form:" << n << '\n' << std::flush;
	return (NULL);
}