/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:53:54 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 15:22:13 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "fstream"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("PresidentialPardonForm", 25, 5),
	target("Home")
{
	std::cout << "|PresidentialPardonForm| default constructor called\n" << std::flush;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &f):
	AForm(f),
	target(f.target)
{
	std::cout << "|PresidentialPardonForm| copy constructor called\n" << std::flush;
	if (this != &f)
		*this = f;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &t):
AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "|PresidentialPardonForm| argument constructor called\n" << std::flush;
	this->target = t;
}

PresidentialPardonForm::~PresidentialPardonForm() throw()
{
	std::cout << "|PresidentialPardonForm| destructor called\n" << std::flush;
}

const PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &s)
{
	std::cout << "|PresidentialPardonForm| copy assignement constructor called\n" << std::flush;
	if (this != &s){
		AForm::operator=(s);
		this->target = s.target;
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &b)const{
	checkexec(b);
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox\n" << std::flush;
}