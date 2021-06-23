/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:42:17 by jbadia            #+#    #+#             */
/*   Updated: 2021/06/22 12:25:08 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_s(char *str, t_flag flag)
{
	int	counter_char;

	counter_char = 0;
	if (!str)
		str = "(null)";
	if (flag.dot >= 0 && (size_t)flag.dot > ft_strlen(str))
		flag.dot = ft_strlen(str);
	if (flag.minus == 1)
		counter_char += ft_treat_str_wprec(str, flag);
	if (flag.dot >= 0)
		counter_char += ft_treat_width(flag.width, flag.dot, flag.zero);
	else
		counter_char += ft_treat_width(flag.width, ft_strlen(str), flag.zero);
	if (flag.minus == 0)
		counter_char += ft_treat_str_wprec(str, flag);
	return (counter_char);
}

int	ft_putstr_prec(char *str, int precision)
{
	int	counter_char;
	int	i;

	counter_char = 0;
	i = 0;
	while (str[i] && i < precision)
	{
		counter_char += ft_putchar(str[i]);
		i++;
	}
	return (counter_char);
}

int	ft_treat_str_wprec(char *str, t_flag flag)
{
	int	counter_char;

	counter_char = 0;
	if (flag.dot >= 0)
	{
		counter_char += ft_treat_width(flag.dot, ft_strlen(str), flag.zero);
		counter_char += ft_putstr_prec(str, flag.dot);
	}
	else
		counter_char += ft_putstr_prec(str, ft_strlen(str));
	return (counter_char);
}
