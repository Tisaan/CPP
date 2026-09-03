/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:09:47 by tseche            #+#    #+#             */
/*   Updated: 2026/07/30 11:31:31 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("bob"){
	std::cout << "|Bureaucrate| default constructor called\n" << std::flush;
	this->range = 1;
};

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.getName())
{
	std::cout << "|Bureaucrat| copy constructor called\n" << std::flush;
	if (&other != this)
		*this = other;
}

Bureaucrat::Bureaucrat(const std::string s, int g) : name(s)
{
	std::cout << "|Bureaucrat| argument constructor called\n" << std::flush;
	this->setGrade(g);
}

Bureaucrat::~Bureaucrat() throw()
{
	std::cout << "|Bureaucrat| default destructor called\n" << std::flush;
}

const Bureaucrat &Bureaucrat::operator=(const Bureaucrat &a)
{
	this->range = a.getGrade();
	return *this;
}

void Bureaucrat::setGrade(int g)
{
	if (g > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (g < 1)
		throw Bureaucrat::GradeTooLowException();
	this->range = g;
}

void Bureaucrat::incr(){this->setGrade(this->getGrade() - 1);};

void Bureaucrat::decr(){this->setGrade(this->getGrade() + 1);};

const std::string&	Bureaucrat::getName() const{return this->name;};
int		Bureaucrat::getGrade() const {return this->range;};

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "The grade provided is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "The grade provided is too low";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b){
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n" << std::flush;
	return (o);
}