/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:18:18 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 16:14:04 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(){
	Data d = (Data){.field1 = 0, .field2 = 'c', .field3 = "chose"};
	uintptr_t p = Serializer::serialize(&d);
	Data * nd = Serializer::deserialize(p);
	std::cout << "equal[" << (nd == &d) << "]\n" << std::flush;
}