/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:15:39 by tseche            #+#    #+#             */
/*   Updated: 2026/07/01 14:29:33 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <functional>
#include <iostream>


//We can't assert that F is a function, let's hope
template <typename T, typename F> void iter(T l[], const std::size_t lenght, F *f){
	for (size_t i = 0; i < lenght; i++)
		f(l[i]); 
}
