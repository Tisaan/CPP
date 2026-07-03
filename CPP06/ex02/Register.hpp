/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Register.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:26:39 by tseche            #+#    #+#             */
/*   Updated: 2026/06/30 16:10:21 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef REGISTER_HPP
#define REGISTER_HPP

#define REGISTER_DERIVED_CLASS(Derived) \
    namespace { \
        Base* create##Derived() { return new Derived(); } \
        struct Derived##_Registrar { \
            Derived##_Registrar() { \
                if (ChildCount < MAX_DERIVED_CLASS) { \
                    ChildClassName[ChildCount].className = #Derived; \
                    ChildClassName[ChildCount].creator = create##Derived; \
                    ChildCount++; \
                } \
            } \
        } Derived##_instance; \
    }

#endif