/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:23:37 by tseche            #+#    #+#             */
/*   Updated: 2026/07/30 11:29:31 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():
	name("A Document"), sign(false), grade(1), exec(1)
{
	std::cout << "|AForm| default constructor called\n" << std::flush;
};

AForm::AForm(const AForm &f):
	name(f.getName()),
	sign(f.getSignature()),
	grade(f.getSignGrade()),
	exec(f.getExecGrade())
{
	std::cout << "|AForm| copy constructor called\n" << std::flush;
	if (this != &f)
		*this = f;
}

AForm::AForm(const std::string &name, int grade, int exec):
	name(name), sign(false), grade(checkGrade(grade)), exec(checkGrade(exec))
{
	std::cout << "|AForm| argument constructor called\n" << std::flush;
}

AForm::~AForm() throw()
{
	std::cout << "|AForm| destructor called\n" << std::flush;
}

const AForm &AForm::operator=(const AForm &s)
{
	std::cout << "|AForm| copy assignement constructor called\n" << std::flush;
	this->sign = s.getSignature();
	return *this;
}

int AForm::checkGrade(int grade){
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	return (grade);
}

bool AForm::getSignature()const {return this->sign;};
std::string AForm::getName() const {return this->name;};
int AForm::getExecGrade() const {return this->exec;};
int AForm::getSignGrade() const {return this->exec;};

void	AForm::beSigned(const Bureaucrat &b){
	if (b.getGrade() > this->grade)
		throw AForm::GradeTooLowException();
	else
		this->sign = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "The grade provided is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "The grade provided is too low";
}

const char *AForm::NotSignedException::what() const throw() {
	return "The form provided is not signed";
}

std::ostream &operator<<(std::ostream &s, const AForm &f)
{
	s << "AForm:" << f.getName() << ", sign:" << f.getSignature() << "\n" << std::flush;
	return (s);
}

void AForm::checkexec(const Bureaucrat &e) const
{
	if (!this->sign)
		throw NotSignedException();
	else if (e.getGrade() > this->exec)
		throw GradeTooLowException();
}
