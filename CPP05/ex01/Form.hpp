/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:13:28 by tseche            #+#    #+#             */
/*   Updated: 2026/06/24 13:40:37 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Bureaucrat.hpp"

class Form: public std::exception{
	const std::string name;
	bool	sign;
	const int grade;
	const int exec;

	public:
		Form();
		Form(const Form& other);
		Form(const std::string &name, int grade, int exec);
		~Form();

		const Form& operator=(const Form& other);
		std::string getName() const ;
		bool getSignature() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void	beSigned(const Bureaucrat &b);
		int	checkGrade(int grade);

		class GradeTooHighException: public std::exception{
			const char *what() const throw();
		};
		class GradeTooLowException: public std::exception{
			const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &s, const Form &f);