/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:42:07 by jbadia            #+#    #+#             */
/*   Updated: 2021/06/22 12:25:08 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_p(unsigned long long pointer, t_flag flag)
{
	int		char_counter;
	char	*str_pointer;

	char_counter = 0;
	if (flag.dot == 0 && pointer == 0)
	{
		char_counter += ft_putstr("0x");
		char_counter += ft_treat_width(flag.width, 0, 1);
		return (char_counter);
	}
	str_pointer = ft_put_str_hexa(pointer, 1);
	if ((size_t)flag.dot < ft_strlen(str_pointer))
		flag.dot = ft_strlen(str_pointer);
	if (flag.minus == 1)
		char_counter += ft_treat_pwprec(str_pointer, flag);
	char_counter += ft_treat_width(flag.width, ft_strlen(str_pointer) + 2, 0);
	if (flag.minus == 0)
		char_counter += ft_treat_pwprec(str_pointer, flag);
	free(str_pointer);
	return (char_counter);
}

int	ft_treat_pwprec(char *str_pointer, t_flag flag)
{
	int	counter_char;

	counter_char = 0;
	counter_char += ft_putstr("0x");
	if (flag.dot >= 0)
	{
		counter_char += ft_treat_width(flag.dot, ft_strlen(str_pointer), 1);
		counter_char += ft_putstr_prec(str_pointer, flag.dot);
	}
	else
		counter_char += ft_putstr_prec(str_pointer, ft_strlen(str_pointer));
	return (counter_char);
}
