/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:17:58 by tseche            #+#    #+#             */
/*   Updated: 2026/07/14 18:01:02 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){
	std::cout << "|RPN| default constructor called\n" << std::flush;
}

RPN::RPN(const RPN &r){
	std::cout << "|RPN| copy constructor called\n" << std::flush;
	if (this != &r)
		*this = r;
}

RPN::~RPN(){
	std::cout << "|RPN| destructor called\n" << std::flush;
}

RPN &RPN::operator=(const RPN &r){
	std::cout << "|RPN| default constructor called\n" << std::flush;
	if (this != &r)
		*this = r;
	return *this;
}

float add(int a, int b){
	if ((long)(a + b) > INT_MAX)
		return (NAN);
	//std::cout << a << " + " << b << " = " << (int)(a + b) << "\n" << std::flush;
	return (a + b);
}

float sub(int a, int b){
	if ((long)(a - b) < INT_MIN)
		return (NAN);
	//std::cout << a << " - " << b << " = " << (int)(a - b) << "\n" << std::flush;
	return (a - b);
}

float mul(int a, int b){
	if ((long)(a * b) > INT_MAX)
		return (NAN);
	//std::cout << a << " * " << b << " = " << (int)(a * b) << "\n" << std::flush;
	return (a * b);
}

float pdiv(int a, int b){
	if (b == 0)
		return (NAN);
	//std::cout << a << " / " << b << " = " << (int)(a / b) << "\n" << std::flush;
	return (a / b);
}

typedef float (* func)(int, int);

bool ft_isoneof(char c, const std::string &s){
	for (size_t i = 0; i < s.length(); i++)
	{
		if (c == s.at(i))
			return (true);
	}
	return (false);
}

int RPN::evaluate(const std::string &s){
	std::stack<int> stack = std::stack<int>();
	
	struct ftable{
		char type;
		func callback;
	};

	ftable table[48];
	table[static_cast<int>('+')].callback = &add;
	table[static_cast<int>('-')].callback = &sub;
	table[static_cast<int>('*')].callback = &mul;
	table[static_cast<int>('/')].callback = &pdiv;

	for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
	{
		if (*it == ' ')
			continue;
		else if (it == s.begin() && ft_isoneof(*it, "+-*/"))
			goto error;
		else if (!isdigit(*it) && !ft_isoneof(*it, "+-*/"))
			goto error;
		else if (isdigit(*it))
			stack.push((*it - '0'));
		else if (ft_isoneof(*it, "+-*/"))
		{
			if (stack.size() < 2)
				goto error;
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if (ft_isoneof((a + '0'), "+-*/") || ft_isoneof((b + '0'), "+-*/"))
				goto error;
			float res = (*table[static_cast<int>(*it)].callback)(b, a);
			if (res == NAN)
				goto error;
			stack.push(res);
		}
	}
	if (stack.size() > 1)
		goto error;
	std::cout << stack.top() << "\n" << std::flush;
	return (1);
	
	error:
		std::cout << "Error\n" <<std::flush;
		return (0);
}
