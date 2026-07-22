/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:12:22 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 16:27:00 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Base.hpp"

class B: public Base{};

REGISTER_DERIVED_CLASS(B);
/*
namespace {
	Base* createB(){return new B();}
	struct B_Registrar {
		B_Registrar(){
			if (ChildCount < MAX_DERIVED_CLASS){
				ChildClassName[ChildCount].className = "B";
				ChildClassName[ChildCount].creator = createB;
				ChildCount++;
			}
		}
	} B_instance;
}
*/