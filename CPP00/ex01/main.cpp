/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:47:22 by tseche            #+#    #+#             */
/*   Updated: 2026/04/16 15:30:31 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"
#include <iostream>
#include <string>
#include <locale>
#include <iomanip>
#include <sstream>

Contact *get_contact(){
	std::string name;
	std::string surname;
	std::string nickname;
	std::string phone;
	std::string secret;
	std::cout << "\nInput the first name:" << std::flush;	
	while (!(std::cin >> name))
		std::cout << "\nInput the first name:" << std::flush;
	for (size_t i = 0; i < name.length(); i++)
	{
		if (!std::isalpha(name[i]))
		{
			std::cout << "What a weird name\n";
			break ;
		}
	}
	std::cout << "\nInput the surname:" << std::flush;
	while (!(std::cin >> surname))
		std::cout << "\nInput the surname:" << std::flush;
	std::cout << "\nInput the nickname:" << std::flush;
	while (!(std::cin >> nickname))
		std::cout << "\nInput the nickname:" << std::flush;
	std::cout << "\nDamn, what a cute nickname";
	std::cout << "\nInput the phone number:" << std::flush;
	while (!(std::cin >> phone))
		std::cout << "\nInput the phone number:" << std::flush;
	for (size_t i = 0; i < phone.length(); i++)
	{
		if (!std::isdigit(phone[i]))
		{
			std::cout << "Where does the phone number came from? SPACE...?\n";
			break ;
		}
	}
	std::cout << "\nInput his/her dark little secret:" << std::flush;
	while (!(std::cin >> secret))
		std::cout << "Input his/her dark little secret\n" << std::flush;
	Contact *contact;
	try {
		contact = new Contact(name, surname, nickname, phone, secret);
	} catch (const std::bad_alloc& e){
		std::cout << "Allocation failed: " << e.what() << std::endl;
		return (NULL);
	}
	return (contact);
}

void	display(PhoneBook *phone){
	for (int i = 0; i < phone->nbr; i++){
		Contact *c = phone->get(i);
		std::cout << '|' << std::setw(10) << i << std::flush;
		std::cout << '|' << std::setw(10) << ((c->name.length() <= 10) ? c->name : (c->name.substr(0, 9) + "."));
		std::cout << std::flush;
		std::cout << '|' << std::setw(10) << ((c->surname.length() <= 10) ? c->surname : (c->surname.substr(0, 9) + "."));
		std::cout << std::flush;
		std::cout << '|' << std::setw(10) << ((c->nickname.length() <= 10) ? c->nickname : (c->nickname.substr(0, 9) + "."));
		std::cout << '|' <<std::endl;
	}
}


//invalid read sur phone->nbr a la ligne 93 jsp pk
int main(){
	std::string msg = "PhoneBook Command:";
	std::string rep;
	PhoneBook *phone;
	try {
		phone = new PhoneBook();	
	} catch (const std::bad_alloc& e){
		std::cout << "Allocation failed: " << e.what() << std::endl;
		return (1);
	}
	phone->nbr = 0;
	bool add = false;
	while (1){
		if (!add)
			std::cout << msg << std::flush;
		if (!(std::getline(std::cin, rep)))
			break;
		else {
			if (rep == "ADD"){
				if (phone->nbr == 8)
				{
					std::cout << "A contact has been overwritten, type REVERT to undo this";
					phone->nbr = 0;
				}
				phone->add(get_contact());
				phone->nbr++;
				add = true;
			}
			else if (rep == "SEARCH"){
				
				if (phone->nbr == 0)
				{
					std::cout << "No Contact saved" << std::endl;
					continue;
				}
				display(phone);
				
				int indice = -1;
				bool good = true;
				bool cont = false;
				while (good)
				{
					std::cout << "\nIndex:" << std::flush;
					if (!(std::getline(std::cin, rep)))
						std::cout << "\nIndex:" << std::flush;
					else {
						for (int i = 0; rep[i]; i++)
						{
							if (!(std::isdigit(rep[i])))
							{
								cont = true;
								break ;
							}
						}
						if (cont)
							continue;
						std::istringstream iss(rep);
						iss >> indice;
						if (indice >= phone->nbr || indice < 0)
						{
							std::cout << "BRO, the input is invalid\n";
							std::cout << "do you even know how to count??\n";
							std::cout << "Try again, Hopefully you'll get it right\n";
						}
						else
							good = false;
					}
				}
				if (indice != -1)
					phone->display(indice);
			}
			else if (rep == "REVERT")
			{
				std::cout << "Do you really think that i was paid enought for doing this shit" << std::endl;
			}
			else if (rep == "EXIT")
				break ;
			else {
				if (add)
				{
					add = false;
					continue;
				}
				std::cout << "Unknown command" << std::endl;
			}
		}
		std::cout << std::endl;
	}
	delete phone;
}