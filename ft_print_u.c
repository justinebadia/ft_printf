/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:42:23 by jbadia            #+#    #+#             */
/*   Updated: 2021/06/23 08:31:09 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_u(unsigned int u_nb, t_flag flag)
{
	int		counter_char;
	char	*str_unb;

	counter_char = 0;
	u_nb = u_nb + 4294967295 + 1;
	if (flag.dot == 0 && u_nb == 0)
	{
		counter_char += ft_treat_width(flag.width, 0, 0);
		return (counter_char);
	}
	str_unb = ft_uitoa(u_nb);
	counter_char += ft_treat_uint_flag(str_unb, flag);
	free(str_unb);
	return (counter_char);
}

int	ft_treat_uint_flag(char *str_unb, t_flag flag)
{
	int	counter_char;

	counter_char = 0;
	if (flag.minus == 1)
		counter_char += ft_treat_uint_wprec(str_unb, flag);
	if (flag.dot >= 0 && ft_strlen(str_unb) > (size_t)flag.dot)
		flag.dot = ft_strlen(str_unb);
	if (flag.dot >= 0)
	{
		flag.width -= flag.dot;
		counter_char += ft_treat_width(flag.width, 0, 0);
	}
	else
		counter_char += ft_treat_width(flag.width, ft_strlen(str_unb),
				flag.zero);
	if (flag.minus == 0)
		counter_char += ft_treat_uint_wprec(str_unb, flag);
	return (counter_char);
}

int	ft_treat_uint_wprec(char *str_unb, t_flag flag)
{
	int	counter_char;

	counter_char = 0;
	if (flag.dot >= 0)
		counter_char += ft_treat_width(flag.dot, ft_strlen(str_unb), 1);
	counter_char += ft_putstr_prec(str_unb, ft_strlen(str_unb));
	return (counter_char);
}
