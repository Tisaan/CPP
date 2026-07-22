/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Register.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:26:39 by tseche            #+#    #+#             */
/*   Updated: 2026/07/18 18:09:56 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
