/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:12:44 by tseche            #+#    #+#             */
/*   Updated: 2026/08/03 15:02:59 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cstring>
#include <sstream>

typedef struct s_table{
	bool	i;
	bool	f;
	bool	d;
	bool	c;
}				i_table;

struct repr_table
{
	std::string	*i;
	std::string	*f;
	std::string	*d;
	std::string	*c;
};


enum state{
	bpoint,
	apoint,
	point,
	other,
};


struct data;

typedef void (* func)(data *);

struct f_table{
	state	id;
	func callback; 
};

struct data{
	int point;
	s_table	table;
	f_table	*state_table;
	repr_table repr_t;
	size_t *rec;
	size_t len;
	std::string *str;
	bool end;
};

// --------------[LOGIC]------------------ 

data	*init_data(int point,
	i_table	table,
	f_table	*state_table,
	repr_table repr_t,
	size_t *rec,
	std::string &s
)
{
	data	*d = new data;
	d->point = point;
	d->repr_t = repr_t;
	d->state_table = state_table;
	d->table = table;
	d->rec = rec;
	d->len = s.length();
	d->str = &s;
	d->end = false;
	return (d);
}

void	add_char(data *d){
	char &c = d->str->at(d->len - *d->rec -1);
	for (int i = 0; i < 5; i++){
		switch (i){
			case 0:{
				if (d->table.i)
				{
					if (isdigit(c) || c == '.')
						d->repr_t.i->insert(0, 1, c);
					else
					{
						std::stringstream ss;
						ss << static_cast<int>(c);
						std::string tmp = ss.str();
						d->repr_t.i->insert(0, tmp);
					}	
						
				}
				break;
			}
			case 1:{
				if (d->table.f){
					if (isdigit(c) || c == '.' || (c == 'f'))
						d->repr_t.f->insert(0, 1, c);
					else
					{
						std::stringstream ss;
						ss << static_cast<int>(c);
						std::string tmp = ss.str();
						d->repr_t.f->insert(0, tmp);
					}
				}
				break;
			}
			case 2:{
				if (d->table.d && c != 'f')
				{
					if (isdigit(c) || c == '.')
						d->repr_t.d->insert(0, 1, c);
					else
					{
						std::stringstream ss;
						ss << static_cast<int>(c);
						std::string tmp = ss.str();
						d->repr_t.d->insert(0, tmp);
					}
				}
				break;
			}
			case 3:{
				if (d->table.c)
					d->repr_t.c->insert(0, 1, c);
				break;
			}
		}
	}
}

void	fbpoint(data *d)
{
	add_char(d);
}

void fapoint(data *d)
{
	add_char(d);
}

void check(data *d)
{
	size_t f;
	if (d->point)
	{
		if (*d->str == std::string("."))
			return ;
		f = d->str->find('.');
		std::string::iterator it = d->str->begin();
		int count = 0;
		for (; it < d->str->end(); ++it)
		{
			if (*it == '.')
				count++;
		}
		if (f != d->str->npos && count == 1)
		{
			f++;//skip the dot
			int i = 0;
			for (;f < d->str->length(); f++, i++)
			{
				if (f == d->str->length() - 1 && d->str->at(f) == 'f')
					continue;
				if (d->str->at(f) != '0')
					break;
			}
			if (f == d->str->length())
			{
				d->table.c = true;
				d->table.i = true;
				f -= i + 1;
				f == 0 ? (
					d->repr_t.c->assign("0" + d->str->substr(0, f)),
					d->repr_t.i->assign("0" + d->str->substr(0, f)),
					d->repr_t.f->insert(0, 1, '0'),
					d->repr_t.d->insert(0, 1, '0')
				) : (d->repr_t.c->assign(d->str->substr(0, f)),
					d->repr_t.i->assign(d->str->substr(0, f))
				);
			}
		}
	}
	else
	{
		if (*d->str == std::string("f"))
			return ;
		d->repr_t.f->append(".0f");
		d->repr_t.d->append(".0");
	}
}

void	fpoint(data *d)
{
	if (d->point)
	{
		d->table.c = false;
		d->table.d = false;
		d->table.i = false;
		d->table.f = false;
		d->end = true;
		return ;
	}
	else if (*d->str == std::string(".")){
		d->repr_t.i->assign("46");
		d->repr_t.f->assign("46.0f");
		d->repr_t.d->assign("46.0");
		d->repr_t.c->assign(".");
		d->table.c = true;
		d->end = true;
		d->point = true;
		return ;
	}
	else {
		d->point = true;
		add_char(d);
	}
}

void fother(data *d)
{
	if (d->len == 1 && std::isprint(d->str->at(d->len - *d->rec - 1)))
	{
		char c = d->str->at(d->len - *d->rec - 1);
		if (c == 'f')
		{std::cout << "enter\n" << std::flush;
			d->repr_t.i->assign("102");
			d->repr_t.f->assign("102.0f");
			d->repr_t.d->assign("102.0");
			d->repr_t.c->assign("f");
		}
		else
			add_char(d);
		d->end = true;
	} else if (*d->str == std::string("-inf") || *d->str == std::string("+inf") || *d->str == std::string("nan") || *d->str == std::string("inf"))
	{
		d->table.c = false;
		d->table.i = false;
		d->repr_t.f->insert(0, *d->str);
		d->repr_t.d->insert(0, *d->str);
		d->end = true;
	} else if (*d->str == std::string("-inff") || *d->str == std::string("+inff") || *d->str == std::string("nanf"))
	{
		d->table.c = false;
		d->table.i = false;
		d->repr_t.f->insert(0, *d->str);
		d->repr_t.d->insert(0, *d->str);
		d->end = true;
	} else if (*d->rec == 0 && d->str->at(d->len - *d->rec -1) == 'f')
	{
		d->table.c = false;
		d->table.i = false;
		add_char(d);
	} else if ((d->len - *d->rec - 1) == 0 && std::strchr("-+", d->str->at(d->len - *d->rec - 1)))
	{
		add_char(d);
	} else {
		d->table.c = false;
		d->table.d = false;
		d->table.i = false;
		d->table.f = false;
		d->end = true;
	}
}


struct closure{
	func operator()(int i){
		if (i == 0)
			return fbpoint;
		else if (i == 1)
			return fapoint;
		else if (i == 2)
			return fpoint;
		else
			return fother;
	};
};

void	ass_state_table(data *d)
{
	closure c;
	for (int i = 0; i < 4; i++)
	{
		d->state_table[i] = (f_table){.id = (state)i, .callback = c(i)};
	}
}

func change_state(data *d)
{
	if (std::isdigit(d->str->at(d->len - *d->rec -1) && d->point))
		return fapoint;
	else if (std::isdigit(d->str->at(d->len - *d->rec -1)))
		return (fbpoint);
	else if (d->str->at(d->len - *d->rec -1 ) == '.')
		return (fpoint);
	else
		return (fother);
}

void	print(data *d)
{
	check(d);
	for (int i = 0; i < 5; i++){
		switch (i){
			case 0:{
				std::cout << "int:" << (d->table.i ? *d->repr_t.i : std::string("Impossible")) << "\n" << std::flush;
				break;
			}
			case 1:{
				if (d->repr_t.f->at(d->repr_t.f->length() - 1) != 'f')
					d->repr_t.f->append("f");
				if (d->repr_t.f->at(0) == '.')
					d->repr_t.f->insert(0, 1, '0');
				std::cout << "float:" << (d->table.f ? *d->repr_t.f : std::string("Impossible")) << "\n" << std::flush;
				break;
			}
			case 2:{
				if (d->repr_t.d->at(0) == '.')
					d->repr_t.d->insert(0, 1, '0');
				std::cout << "double:" << (d->table.d ? *d->repr_t.d : std::string("Impossible")) << "\n" << std::flush;
				break;
			}
			case 3:{
				if (d->len == 1 && std::isalpha(d->repr_t.c->at(0)))
				{
					std::cout << "char:" << d->repr_t.c->at(0) << "\n" << std::flush;
				}
				else
				{
					long l = strtol(d->repr_t.c->c_str(), NULL, 10);
					if (l < 0 || l > 127)
						d->table.c = false;
					bool check = false;
					bool num = false;
					size_t len = d->repr_t.c->length();
					for (size_t i = 0; i < len; i++)
					{
						if (num == false && (d->repr_t.c->at(i) == '-' || d->repr_t.c->at(i) == '+'))
							continue;
						else if (isdigit(d->repr_t.c->at(i)))
						{
							num = true;
							if (i == len - 1)
								check = true;
						}
						else
							break;
					}
					if (check)
					{
						char c = static_cast<char>(l);
						if (isprint(c))
							d->repr_t.c->assign(std::string("'") += c).append("'");
						else
							d->repr_t.c->assign("Non Displayable");
					}
					else
					{
						if (d->repr_t.c->length() == 1)
						{
							if (!std::isprint(d->repr_t.c->at(0)))
								d->repr_t.c->assign("Non Displayable");
							else
								d->repr_t.c->assign(std::string("'") += d->repr_t.c->at(0)).append("'");
						}
						else
							d->table.c = false;
					}
					std::cout << "char:" << (d->table.c ? *d->repr_t.c : std::string("Impossible")) << "\n" << std::flush;
				}
				break;
			}
		}
	}
}

ScalarConverter::ScalarConverter(){std::cout << "default constructor called\n" << std::flush;}

ScalarConverter::~ScalarConverter(){std::cout << "destructor called\n" << std::flush;}


ScalarConverter::ScalarConverter(const ScalarConverter &s){
	std::cout << "copy constructor called\n" << std::flush;
	if (this != &s)
		*this = s;
}


ScalarConverter &ScalarConverter::operator=(const ScalarConverter &s){
	std::cout << "copy constructor called\n" << std::flush;
	if (this != &s)
		*this = s;
	return (*this);
}

void ScalarConverter::convert(std::string &s)
{
	static	i_table table = {.i = true, .f = true, .d = true, .c = true};
	static	f_table	*state_table = new f_table[4];
	static size_t 		rec = 0;
	static data	*d = NULL;

	if (rec == 0)
	{
		if (s == "")
		{
			delete[] state_table;
			return ;
		}
		repr_table repr_t = {
			.i = new std::string(""),
			.f = new std::string(""),
			.d = new std::string(""),
			.c = new std::string(""),
		};
		d = init_data(0, table, state_table, repr_t, &rec, s);
		ass_state_table(d);
	}
	else if (rec == d->len
		|| d->end)
	{
		print(d);
		delete[] state_table;
		delete d->repr_t.i;
		delete d->repr_t.f;
		delete d->repr_t.d;
		delete d->repr_t.c;
		delete d;
		return ;
	}
	(change_state(d))(d);
	if (d->end)
	{
		print(d);
		delete[] state_table;
		delete d->repr_t.i;
		delete d->repr_t.f;
		delete d->repr_t.d;
		delete d->repr_t.c;
		delete d;
		return ;
	}
	rec++;
	convert(s);
}