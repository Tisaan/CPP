/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:13:49 by tseche            #+#    #+#             */
/*   Updated: 2026/06/30 16:04:27 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *Base::generate(){
	return (Base::create(Base::ChildClassName[std::rand() % 3].className));
}

void Base::identify(Base *b){
	if (dynamic_cast<A *>(b))
		std::cout << "Type is A\n" << std::flush;
	else if (dynamic_cast<B *>(b))
		std::cout << "Type is B\n" << std::flush;
	else if (dynamic_cast<A *>(b))
		std::cout << "Type is C\n" << std::flush;
	else
		std::cout << "Unknown Type\n" << std::flush;
}

void Base::identify(Base &b){
	try{
		Base *unusedValue = dynamic_cast<A *>(&b);
		std::cout << "Type is A\n" << std::flush;
		return ;
	} catch (std::exception &e){}
	try{
		Base *unusedValue = dynamic_cast<B *>(&b);
		std::cout << "Type is B\n" << std::flush;
		return ;
	} catch (std::exception &e){}
	try{
		Base *unusedValue = dynamic_cast<C *>(&b);
		std::cout << "Type is C\n" << std::flush;
		return ;
	} catch (std::exception &e){}
	std::cout << "Unknown Type\n" << std::flush;
}