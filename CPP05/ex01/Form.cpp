/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:23:37 by tseche            #+#    #+#             */
/*   Updated: 2026/06/24 13:40:30 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): grade(1), exec(1), name("A Document"), sign(false){std::cout << "|Form| default constructor called\n" << std::flush;};

Form::Form(const Form &f): grade(f.getSignGrade()), exec(f.getExecGrade()), name(f.getName()), sign(f.getSignature())
{
	std::cout << "|Form| copy constructor called\n" << std::flush;
	if (this != &f)
		*this = f;
}

Form::Form(const std::string &name, int grade, int exec): name(name), grade(checkGrade(grade)), exec(checkGrade(exec)), sign(false){
	std::cout << "|Form| argument constructor called\n" << std::flush;
}

Form::~Form(){std::cout << "|Form| destructor called\n" << std::flush;}

const Form &Form::operator=(const Form &s)
{
	std::cout << "|Form| copy assignement constructor called\n" << std::flush;
	this->sign = s.getSignature();
	return *this;
}

int Form::checkGrade(int grade){
	if (grade > 150)
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
	return (grade);
}

bool Form::getSignature()const {return this->sign;};
std::string Form::getName() const {return this->name;};
int Form::getExecGrade() const {return this->exec;};
int Form::getSignGrade() const {return this->exec;};

void	Form::beSigned(const Bureaucrat &b){
	if (b.getGrade() >= this->grade)
		throw Form::GradeTooLowException();
	else
		this->sign = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "The grade provided is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "The grade provided is too low";
}

std::ostream &operator<<(std::ostream &s, const Form &f)
{
	s << "Form:" << f.getName() << ", sign:" << f.getSignature() << "\n" << std::flush;
	return (s);
}
