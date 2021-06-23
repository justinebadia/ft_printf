/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:42:32 by jbadia            #+#    #+#             */
/*   Updated: 2021/06/23 08:35:55 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_treat_width(int width, int len, int zero)
{
	int	char_counter;

	char_counter = 0;
	while (width - len > 0)
	{
		if (zero == 1)
			char_counter += ft_putchar('0');
		else
			char_counter += ft_putchar(' ');
		width--;
	}
	return (char_counter);
}

t_flag	ft_flag_width(va_list args, t_flag flag)
{
	flag.star = 1;
	flag.width = va_arg(args, int);
	if (flag.width < 0)
	{
		flag.minus = 1;
		flag.width *= -1;
		flag.zero = 0;
	}
	return (flag);
}

t_flag	ft_flag_minus(t_flag flag)
{
	flag.minus = 1;
	flag.zero = 0;
	return (flag);
}

int	ft_dot_flag(const char *str, int i, t_flag *flag, va_list arg)
{
	if (str[i] == '*')
	{
		flag->dot = va_arg(arg, int);
		i++;
	}
	else
	{
		flag->dot = 0;
		if (ft_isdigit(str[i]))
		{
			flag->dot = ft_atoi(&str[i]);
			while (ft_isdigit(str[i]))
				i++;
		}
	}
	if (flag->dot < 0)
	{
		flag->dot = -1;
	}
	return (i);
}
