/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:09:09 by tseche            #+#    #+#             */
/*   Updated: 2026/06/30 16:07:26 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>
#include <iostream>
#include <cstring>
#include "Register.hpp"

const std::size_t MAX_DERIVED_CLASS = 3;

struct ChildClassInfo {
    std::string className;
    Base* (*creator)();
};

class Base{
	public:
		virtual ~Base();
};

static ChildClassInfo ChildClassName[MAX_DERIVED_CLASS];
static std::size_t ChildCount;
static Base* create(const std::string& className) { 		 	
    for (size_t i = 0; i < ChildCount; ++i) {
        if (ChildClassName[i].className == className) {
            return ChildClassName[i].creator();
        }
    }
    return 0; // Return nullptr if class not found
}

Base *generate();
void identify(Base *b);
void identify(Base &b);

ChildClassInfo ChildClassName[MAX_DERIVED_CLASS];
size_t ChildCount = 0;