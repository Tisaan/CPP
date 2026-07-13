/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:17:58 by tseche            #+#    #+#             */
/*   Updated: 2026/07/13 19:36:33 by tseche           ###   ########.fr       */
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

float RPN::add(int a, int b){
	if ((long)(a + b) > INT_MAX)
		return (NAN);
	return (a + b);
}

float RPN::sub(int a, int b){
	if ((long)(a - b) < INT_MIN)
		return (NAN);
	return (a - b);
}

float RPN::add(int a, int b){
	if ((long)(a * b) > INT_MAX)
		return (NAN);
	return (a * b);
}

float RPN::add(int a, int b){
	if (b == 0)
		return (NAN);
	return (a / b);
}

typedef float (RPN::*func)(int, int);

int RPN::evaluate(const std::string &s){
	struct ftable{
		char type;
		func callback;
	};

	const ftable table[] = {
		{.type = '+', .callback=&RPN::add},
		{.type = '-', .callback=&RPN::sub},
		{.type = '*', .callback=&RPN::mul},
		{.type = '/', .callback=&RPN::div}
	};
}
