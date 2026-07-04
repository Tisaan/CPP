/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 19:01:26 by tseche            #+#    #+#             */
/*   Updated: 2026/07/04 14:58:26 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::srand(time(NULL));
	Span s(10000);
	std::cout << "Test 10000 number\n" << std::flush;
	for (int i = 0; i < 10000; i++)
		s.addNumber(std::rand());
	std::cout << "max[" << s.longestSpan() << "]\n" << std::flush;
	std::cout << "min[" << s.shortestSpan() << "]\n" << std::flush;

	try{
		s.addNumber(10);
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << "\n" << std::flush;
	}
	
	std::cout << "Test with reduce number\n" << std::flush;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	//expected; {.max[14], .min[2]}
	std::cout << "max[" << sp.longestSpan() << "]\n" << std::flush;
	std::cout << "min[" << sp.shortestSpan() << "]\n" << std::flush;

	std::cout << "Test with empty Span\n" << std::flush;
	Span span = Span();
	try {
		span.longestSpan();
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << "\n" << std::flush;
	}
	try {
		span.addNumber(2);
	} catch (std::runtime_error &e)
	{
		std::cout << e.what() << "\n" << std::flush;
	}
	Span spa = Span(1);
	spa.addNumber(0);
	try {
		spa.longestSpan();
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << "\n" << std::flush;
	}
}