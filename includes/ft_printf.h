/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:39:13 by jbadia            #+#    #+#             */
/*   Updated: 2021/06/23 08:38:07 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_flag
{
	int	minus;
	int	width;
	int	dot;
	int	zero;
	int	conversion;
	int	star;
}				t_flag;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_putstr(char *str);
int		ft_putchar(char c);

int		ft_print_c(char c, t_flag flag);
int		ft_print_s(char *str, t_flag flag);
int		ft_print_d(long nb, t_flag flag);
int		ft_print_hexa(unsigned int u_nb, int lower, t_flag flag);
int		ft_print_u(unsigned int u_nb, t_flag flag);
int		ft_print_p(unsigned long long pointer, t_flag flag);
int		ft_print_percent (t_flag flag);
int		ft_print_n(va_list args, int char_counter);

char	*ft_convert_utohex(unsigned long long nb_unsigned, int lower,
			char *str_hexa, int len);
char	*ft_put_str_hexa(unsigned long long nb, int lower);
int		ft_treat_hex_flag(char *str_hexa, t_flag flag);
int		ft_treat_strhexa_wprec(char *str_hexa, t_flag flag);
int		ft_treat_pwprec(char *str_pointer, t_flag flag);

int		ft_type_handle (int c);
int		ft_conv(int c, t_flag flag, va_list args, int n_count);
int		itoa_length(long n);
char	*pre_itoa(char	*str, long nb, int len, int is_negative);
char	*ft_uitoa(unsigned int n);
char	*ft_itoa_p(long n);

int		ft_parsing_flags(t_flag *flag, const char *str, int i, va_list args);
t_flag	init_flags(void);
int		ft_treat_width(int width, int len, int zero);
t_flag	ft_flag_isdigit(char c, t_flag flag);
t_flag	ft_flag_width(va_list args, t_flag flag);
t_flag	ft_flag_minus(t_flag flag);
int		ft_dot_flag(const char *str, int i, t_flag *flag, va_list arg);
int		ft_putstr_prec(char *str, int precision);
int		ft_treat_str_wprec(char *str, t_flag flag);

int		ft_treat_uint_flag(char *str_unb, t_flag flag);
int		ft_treat_uint_wprec(char *str_unb, t_flag flag);

int		ft_treat_int_wprec(char *str_int, int nb, t_flag flag);
int		ft_treat_int_flag(char *str_int, int nb, t_flag flag);

int		ft_read_str(const char *str, va_list args, int counter_char);
int		ft_printf(const char *str_format, ...);

#endif
