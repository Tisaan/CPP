/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:49:13 by tseche            #+#    #+#             */
/*   Updated: 2026/07/30 10:22:45 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

class Bureaucrat{
	const std::string name;
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
		class GradeTooHighException: public std::exception{
			const char *what() const throw();
		};
		class GradeTooLowException: public std::exception{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);