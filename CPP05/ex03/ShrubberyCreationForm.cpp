/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:53:54 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 15:26:54 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreationForm", 145, 137),
	target("Home")
{
	std::cout << "|ShrubberyCreationForm| default constructor called\n" << std::flush;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &f):
	AForm(f),
	target(f.target)
{
	std::cout << "|ShrubberyCreationForm| copy constructor called\n" << std::flush;
	if (this != &f)
		*this = f;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &t):
AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "|ShrubberyCreationForm| argument constructor called\n" << std::flush;
	this->target = t;
}

ShrubberyCreationForm::~ShrubberyCreationForm()throw()
{
	std::cout << "|ShrubberyCreationForm| destructor called\n" << std::flush;
}

const ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s)
{
	std::cout << "|ShrubberyCreationForm| copy assignement constructor called\n" << std::flush;
	if (this != &s){
		AForm::operator=(s);
		this->target = s.target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &b)const{
	checkexec(b);
	std::ofstream file((this->target + "_shrubbery").c_str());
	file << "       *      \n";
	file << "      ***     \n";
	file << "     *****    \n"; 
	file << "    *******   \n";
	file << "   *********  \n";
	file << "  *********** \n";
	file << "      | |     \n";
	file << "      | |     \n";
	file << "      |_|     \n";
}