/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_castflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 22:12:26 by saxiao            #+#    #+#             */
/*   Updated: 2017/12/22 03:04:38 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int				is_f(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||\
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||\
			c == 'x' || c == 'X' || c == 'c' || c == 'C');
}

static	void	init(t_data *data)
{
	data->ori = NULL;
	ft_bzero(data->flags, 10);
	data->width = 0;
	data->precison = -1;
	data->len = 0;
	data->no_pre = 0;
	data->blank = 0;
	data->cast = none;
}

void			set_cast(t_data *data, char *format, int size)
{
	init(data);
	if (ft_strnchr(format, 'h', size))
	{
		if (ft_strnchr_double(format, 'h', size))
			data->cast = hh;
		else
			data->cast = h;
	}
	else if (ft_strnchr(format, 'l', size))
	{
		if (ft_strnchr_double(format, 'l', size))
			data->cast = ll;
		else
			data->cast = l;
	}
	else if (ft_strnchr(format, 'j', size))
		data->cast = j;
	else if (ft_strnchr(format, 'z', size))
		data->cast = z;
	else
		data->cast = none;
}

static	void	set_zero_flag(t_data *data, int *i, int *j, char *format)
{
	if (format[*i] == '.')
	{
		data->precison = ft_atoi(format + 1 + *i);
		*i = *i + nb_digit(format + *i + 1) + 1;
	}
	else
	{
		if (ft_strchr("#-+ ", format[*i]))
		{
			data->flags[*j] = format[*i];
			(*j)++;
		}
		(*i)++;
	}
}

void			set_flags(t_data *data, char *format, int size)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < size && j < 10)
	{
		if (format[i] == '0')
		{
			if (!(ft_strchr(data->flags, '0')))
				data->flags[j++] = '0';
			i++;
		}
		else if ('0' < format[i] && format[i] <= '9')
		{
			data->width = ft_atoi(format + i);
			i = i + nb_digit(format + i);
		}
		else
			set_zero_flag(data, &i, &j, format);
	}
}
