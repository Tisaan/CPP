/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:13:49 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 16:23:58 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){
	std::cout << "|Base| destructor called\n" << std::flush;
}

Base *generate(){
	static int i = 0;
	if (i == 0 && i++)
		srand(time(NULL));
	return (create(ChildClassName[rand() % 3].className));
}

Base* create(const std::string& className)
{
    for (size_t i = 0; i < ChildCount; ++i) {
        if (ChildClassName[i].className == className) {
            return ChildClassName[i].creator();
        }
    }
    return 0; // Return nullptr if class not found
}

void identify(Base *b){
	if (dynamic_cast<A *>(b))
		std::cout << "Type is A\n" << std::flush;
	else if (dynamic_cast<B *>(b))
		std::cout << "Type is B\n" << std::flush;
	else if (dynamic_cast<A *>(b))
		std::cout << "Type is C\n" << std::flush;
	else
		std::cout << "Unknown Type\n" << std::flush;
}

void identify(Base &b){
	try{
		Base *unusedValue = dynamic_cast<A *>(&b);
		std::cout << "Type is A\n" << std::flush;
		(void)unusedValue ;
		return ;
	} catch (std::exception &e){}
	try{
		Base *unusedValue = dynamic_cast<B *>(&b);
		std::cout << "Type is B\n" << std::flush;
		(void)unusedValue ;
		return ;
	} catch (std::exception &e){}
	try{
		Base *unusedValue = dynamic_cast<C *>(&b);
		std::cout << "Type is C\n" << std::flush;
		(void)unusedValue ;
		return ;
	} catch (std::exception &e){}
	std::cout << "Unknown Type\n" << std::flush;
}