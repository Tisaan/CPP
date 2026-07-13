/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:13:08 by tseche            #+#    #+#             */
/*   Updated: 2026/07/13 19:24:55 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include <climits>

class RPN{
	float add(int a, int b);
	float sub(int a, int b);
	float mul(int a, int b);
	float div(int a, int b);
	public:
		RPN();
		RPN(const RPN &);
		~RPN();
		
		RPN &operator=(const RPN &);
		
		int evaluate(const std::string &);
};