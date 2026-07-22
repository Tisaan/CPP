/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:13:28 by tseche            #+#    #+#             */
/*   Updated: 2026/06/24 13:18:15 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Bureaucrat.hpp"

class AForm: public std::exception{
	const std::string name;
	bool	sign;
	const int grade;
	const int exec;

	public:
		AForm();
		AForm(const AForm& other);
		AForm(const std::string &name, int grade, int exec);
		~AForm() throw();

		const AForm& operator=(const AForm& other);
		std::string getName() const ;
		bool getSignature() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void	beSigned(const Bureaucrat &b);
		int	checkGrade(int grade);
		virtual void execute(const Bureaucrat &ex)const = 0;
		void	checkexec(const Bureaucrat &b) const;

		class GradeTooHighException: public std::exception{
			const char *what() const throw();
		};
		class GradeTooLowException: public std::exception{
			const char *what() const throw();
		};
		class NotSignedException: public std::exception{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &s, const AForm &f);