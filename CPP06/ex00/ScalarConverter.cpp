/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:12:44 by tseche            #+#    #+#             */
/*   Updated: 2026/06/25 16:22:58 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

struct s_table{
	bool	i;
	bool	f;
	bool	d;
	bool	c;
};

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

using i_table = s_table;

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
	int *rec;
	size_t len;
	std::string *str;
};

// --------------[LOGIC]------------------ \\

data	*init_data(int point,
	i_table	table,
	f_table	*state_table,
	repr_table repr_t,
	int *rec,
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
	return (d);
}

void	add_char(data *d){
	for (int i = 0; i < 5; i++){
		switch (i){
			case 0:{
				if (d->table.i)
					d->repr_t.i->insert(0, 1, d->str[d->len - *d->rec]);
				break;
			}
			case 1:{
				if (d->table.f)
					d->repr_t.f->insert(0, 1, d->str[d->len - *d->rec]);
				break;
			}
			case 2:{
				if (d->table.f)
					d->repr_t.f->insert(0, 1, d->str[d->len - *d->rec]);
				break;
			}
			case 3:{
				if (d->table.c)
					d->repr_t.c->insert(0, 1, d->str[d->len - *d->rec]);
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

void	fpoint(data *d)
{
	d->table.i = false;
	d->table.c = false;
	if (*d->rec > 52)
		d->table.d = false;
	else if (*d->rec > 23)
		d->table.f = false;
	add_char(d);
}

void fother(data *d)
{
	if (d->rec == 0)
	{
		if (d->str[d->len - *d->rec] == "f")
		{
			d->table.c = false;
			d->table.d = false;
			d->table.i = false;
			add_char(d);
		}
	}
	else
	{
		d->table.c = false;
		d->table.d = false;
		d->table.i = false;
		d->table.f = false;
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
		d->state_table[i] = {
			.id = (state)i,
			.callback = c(i),
		};
	}
}

func change_state(data *d)
{
	std::cout << d->str->at(d->len - *d->rec) << "\n" << std::flush;
	if (std::isdigit(d->str->at(d->len - *d->rec) && d->point))
		return fapoint;
	else if (std::isdigit(d->str->at(d->len - *d->rec)))
		return (fbpoint);
	else if (d->str->at(d->len - *d->rec) == '.')
		return (fpoint);
	else
		return (fother);
}

void	print(data *d)
{
	
}

void ScalarConverter::convert(std::string &s)
{
	static	int		point =  0;
	static	auto	repr = --s.end();
	static	i_table table = {.i = true, .f = true, .d = true, .c = true};
	static	bool	f = true;
	static	f_table	*state_table = new f_table[4];
	static int 		rec = 0;
	data	*d;

	if (rec == 0)
	{
		repr_table repr_t = {
			.i = new std::string(""),
			.f = new std::string(""),
			.d = new std::string(""),
			.c = new std::string(""),
		};
		d = init_data(0, table, state_table, repr_t, &rec, s);
		ass_state_table(d);
	}
	else if (rec == d->len)
	{
		print(d);
		return ;
	}
	(change_state(d))(d);
	rec++;
	convert(s);
}