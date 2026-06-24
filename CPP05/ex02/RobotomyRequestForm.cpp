/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:53:54 by tseche            #+#    #+#             */
/*   Updated: 2026/06/24 14:40:01 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "fstream"

RobotomyRequestForm::RobotomyRequestForm():
	target("Home"),
	AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "|RobotomyRequestForm| default constructor called\n" << std::flush;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &f):
	AForm(f),
	target(f.target)
{
	std::cout << "|RobotomyRequestForm| copy constructor called\n" << std::flush;
	if (this != &f)
		*this = f;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &t):
AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "|RobotomyRequestForm| argument constructor called\n" << std::flush;
	this->target = t;
}

RobotomyRequestForm::~RobotomyRequestForm(){std::cout << "|RobotomyRequestForm| destructor called\n" << std::flush;}

const RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &s)
{
	std::cout << "|RobotomyRequestForm| copy assignement constructor called\n" << std::flush;
	if (this != &s){
		AForm::operator=(s);
		this->target = s.target;
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &b)const{
	checkexec(b);
	std::cout << "[drilling noises]\n" << std::flush;
	if (std::rand() % 2)
		std::cout << "The robotomy has been successfull\n" << std::flush;
	else
		std::cout << "The robotomy has failed miserably\n" << std::flush;
}