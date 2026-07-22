/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:13:08 by tseche            #+#    #+#             */
/*   Updated: 2026/07/14 17:57:57 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include <climits>
#include <stack>

class RPN{
	public:
		RPN();
		RPN(const RPN &);
		~RPN();
		
		RPN &operator=(const RPN &);
		
		static int evaluate(const std::string &);
};