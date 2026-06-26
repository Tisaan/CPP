/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:12:44 by tseche            #+#    #+#             */
/*   Updated: 2026/06/26 16:55:24 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
	for (int i = 0; i < 5; i++){
		switch (i){
			case 0:{
				if (d->table.i)
					d->repr_t.i->insert(0, 1, d->str->at(d->len - *d->rec -1 ));
				break;
			}
			case 1:{
				if (d->table.f)
					d->repr_t.f->insert(0, 1, d->str->at(d->len - *d->rec -1 ));
				break;
			}
			case 2:{
				if (d->table.d)
					d->repr_t.d->insert(0, 1, d->str->at(d->len - *d->rec -1 ));
				break;
			}
			case 3:{
				if (d->table.c)
					d->repr_t.c->insert(0, 1, d->str->at(d->len - *d->rec -1 ));
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
		f = d->str->find('.');
		std::string::iterator it = d->str->begin();
		int count = 0;
		for (; it < d->str->end(); it++)
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
	d->table.i = false;
	d->table.c = false;
	if (*d->rec > 52)
		d->table.d = false;
	else if (*d->rec > 23)
		d->table.f = false;
	d->point = true;
	add_char(d);
}

void fother(data *d)
{
	if (*d->rec == 0 && d->str->at(d->len - *d->rec -1) == 'f')
	{
		std::cout << "enet\n" << std::flush;
		d->table.c = false;
		d->table.d = false;
		d->table.i = false;
		add_char(d);
	}
	else {
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
	std::cout << "len[" << d->len << "], rec[" << *d->rec << "]\n" << std::flush;
	std::cout << d->str->at(d->len - *d->rec -1 ) << "\n" << std::flush;
	if (std::isdigit(d->str->at(d->len - *d->rec -1 ) && d->point))
		return fapoint;
	else if (std::isdigit(d->str->at(d->len - *d->rec -1 )))
		return (fbpoint);
	else if (d->str->at(d->len - *d->rec -1 ) == '.')
		return (fpoint);
	else
		return (fother);
}

void	print(data *d)
{
	std::cout << "end\n" << std::flush;
	check(d);
	for (int i = 0; i < 5; i++){
		switch (i){
			case 0:{
				std::cout << "int:" << (d->table.i ? *d->repr_t.i : std::string("Impossible")) << "\n" << std::flush;
				break;
			}
			case 1:{
				std::cout << "float:" << (d->table.f ? *d->repr_t.f : std::string("Impossible")) << "\n" << std::flush;
				break;
			}
			case 2:{
				std::cout << "double:" << (d->table.d ? *d->repr_t.d : std::string("Impossible")) << "\n" << std::flush;
				break;
			}
			case 3:{
				std::cout << "char:" << (d->table.c ? *d->repr_t.c : std::string("Impossible")) << "\n" << std::flush;
				break;
			}
		}
	}
}

void ScalarConverter::convert(std::string &s)
{
	static	i_table table = {.i = true, .f = true, .d = true, .c = true};
	static	f_table	*state_table = new f_table[4];
	static size_t 		rec = 0;
	static data	*d = NULL;

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
	else if (rec == d->len
		|| d->end)
	{
		print(d);
		return ;
	}
	(change_state(d))(d);
	if (d->end)
	{
		print(d);
		return ;
	}
	rec++;
	convert(s);
}