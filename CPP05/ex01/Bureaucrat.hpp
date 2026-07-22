/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:49:13 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 15:07:50 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

class Form;

class Bureaucrat: public std::exception{
	std::string name;
	int			range;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& srcBureaucrat);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat() throw();

		const Bureaucrat& operator=(const Bureaucrat& srcBureaucrat);

		const std::string&	getName() const;
		int					getGrade() const;
		void				setGrade(int );
		void				incr();
		void				decr();
		void				signForm(Form &b);
		class GradeTooHighException: public std::exception{
			const char *what() const throw();
		};
		class GradeTooLowException: public std::exception{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);