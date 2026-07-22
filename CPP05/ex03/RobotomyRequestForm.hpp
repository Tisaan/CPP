/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:11:46 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 15:27:37 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <cmath>

class RobotomyRequestForm: public AForm{
	std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm(const std::string &t);
		~RobotomyRequestForm() throw();

		const RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		void execute(const Bureaucrat &e) const;
};