/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:40:48 by jbadia            #+#    #+#             */
/*   Updated: 2021/06/23 08:33:30 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_type_handle (int c)
{
	if (c == 'c')
		return ('c');
	if (c == 's')
		return ('s');
	if (c == '%')
		return ('%');
	if (c == 'X')
		return ('X');
	if (c == 'x')
		return ('x');
	if (c == 'd')
		return ('d');
	if (c == 'i')
		return ('i');
	if (c == 'u')
		return ('u');
	if (c == 'p')
		return ('p');
	if (c == 'n')
		return ('n');
	return (0);
}

int	ft_conv(int c, t_flag flag, va_list args, int n_count)
{
	int	char_counter;

	char_counter = 0;
	if (c == 'c')
		char_counter = ft_print_c(va_arg(args, int), flag);
	if (c == 's')
		char_counter = ft_print_s(va_arg(args, char *), flag);
	if (c == '%')
		char_counter += ft_print_percent(flag);
	if (c == 'X')
		char_counter += ft_print_hexa(va_arg(args, unsigned int), 0, flag);
	if (c == 'x')
		char_counter += ft_print_hexa(va_arg(args, unsigned int), 1, flag);
	if (c == 'd' || c == 'i')
		char_counter += ft_print_d(va_arg(args, int), flag);
	if (c == 'u')
		char_counter += ft_print_u(va_arg(args, unsigned int), flag);
	if (c == 'p')
		char_counter += ft_print_p(va_arg(args, unsigned long), flag);
	if (c == 'n')
		char_counter += ft_print_n(args, n_count);
	return (char_counter);
}

t_flag	init_flags(void)
{
	t_flag	flag;

	flag.dot = -1;
	flag.minus = 0;
	flag.width = 0;
	flag.zero = 0;
	flag.star = 0;
	flag.conversion = 0;
	return (flag);
}

int	ft_parsing_flags(t_flag *flag, const char *str, int i, va_list args)
{
	while (str[i])
	{
		if (str[i] == '0' && flag->minus == 0 && flag->width == 0)
			flag ->zero = 1;
		if (str[i] == '.')
			i = ft_dot_flag(str, i + 1, flag, args);
		if (str[i] == '-')
			*flag = ft_flag_minus(*flag);
		if (str[i] == '*')
			*flag = ft_flag_width(args, *flag);
		if (ft_isdigit(str[i]) && flag->width == 0)
			flag->width = ft_atoi(&str[i]);
		if (ft_type_handle(str[i]))
		{
			flag->conversion = str[i];
			break ;
		}
		i++;
	}
	return (i);
}
