/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:54:36 by saxiao            #+#    #+#             */
/*   Updated: 2017/12/21 23:45:23 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdint.h>
#include <stdarg.h>
#include <wchar.h>
#include <string.h>

typedef enum	s_cast
{
	none = 1,
	hh,
	h,
	l,
	ll,
	j,
	z,
}		t_cast;

typedef	struct	s_data
{
	char	*ori;
	char	flags[10];
	int		width;
	int		precison;
	int		no_pre;
	int		len;
	int		blank;
	t_cast	cast;
}			t_data;

#define NB_CON	15
typedef	struct	s_mark
{
	int		i;
	int		j;
	int		nbr;
	int		per;
}				t_mark;

typedef struct s_fu
{
	char	c;

	void (*func)(va_list, t_data *, char *, int);
}				t_fu;

void	con_d(va_list args, t_data *data, char *foamat, int size);
void	con_bigd(va_list args, t_data *data, char *foamat, int size);
void	con_i(va_list args, t_data *data, char *foamat, int size);
void	con_c(va_list args, t_data *data, char *foamat, int size);
void	con_bigc(va_list args, t_data *data, char *foamat, int size);
void	con_s(va_list args, t_data *data, char *foamat, int size);
void	con_bigs(va_list args, t_data *data, char *foamat, int size);
void	con_o(va_list args, t_data *data, char *foamat, int size);
void	con_bigo(va_list args, t_data *data, char *foamat, int size);
void	con_u(va_list args, t_data *data, char *foamat, int size);
void	con_bigu(va_list args, t_data *data, char *foamat, int size);
void	con_p(va_list args, t_data *data, char *foamat, int size);
void	con_per(va_list args, t_data *data, char *foamat, int size);
void	con_x(va_list args, t_data *data, char *foamat, int size);
void	con_bigx(va_list args, t_data *data, char *foamat, int size);
void	set_flags(t_data *fl, char *format, int size);
void	set_print_oxu_hash(t_data *data, char *pre_fix);
void	set_print_d(t_data *data);
void	put_zero_d(t_data *data);
void	go_right_oux(t_data *data, char *pre_fix);
void	put_zero_oux(t_data *data);
char	*ft_itoa_max(intmax_t n);
char	*ft_itoa_unmax(uintmax_t n);
char	*ft_itoa_short(short n);
char	*ft_itoa_signchar(char n);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*itoa_base(uintmax_t nb, int from, int to);
char	*itoa_hex(uintmax_t nb, char x);
int		max_2(int x, int y);
int		max_3(int x, int y, int z);
int		nb_digit(char *str);
int		is_format(char c);
uintmax_t	nb_dg_inbase(uintmax_t n, unsigned int base_to);
void	ft_putnstr(char *s, int nbr);
void	ft_putnwstr(wchar_t *s, int nbr);
void	ft_putnchar(char c, int nbr);
char	*ft_strnchr(const char *s, int c, int size);
int		ft_strnchr_double(const char *s, int c, int size);
void	ft_putwchar(wchar_t we);
void	ft_putnwchar(wchar_t *we, int nbr);
size_t	ft_wstrlen(wchar_t *we);
void	set_cast(t_data *data, char *format, int size);
int		ft_printf(const char *restrict format, ...);

t_fu	set[NB_CON] =
{
	{'s',con_s},
	{'S',con_bigs},
	{'o',con_o},
	{'O',con_bigo},
	{'d',con_d},
	{'D',con_bigd},
	{'i',con_d},
	{'c',con_c},
	{'C',con_bigc},
	{'u',con_u},
	{'%',con_per},
	{'p',con_p},
	{'U',con_bigu},
	{'x',con_x},
	{'X',con_bigx}
};

#endif