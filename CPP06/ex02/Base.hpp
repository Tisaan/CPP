/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:09:09 by tseche            #+#    #+#             */
/*   Updated: 2026/07/15 16:23:22 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <iostream>
#include <cstring>
#include <cmath>
#include "Register.hpp"

const std::size_t MAX_DERIVED_CLASS = 3;

class Base;

struct ChildClassInfo {
    std::string className;
    Base* (*creator)();
};

class Base{
	public:
		virtual ~Base();
};

static ChildClassInfo ChildClassName[MAX_DERIVED_CLASS];
static std::size_t ChildCount = 0;
Base* create(const std::string& className);

Base *generate();
void identify(Base *b);
void identify(Base &b);
