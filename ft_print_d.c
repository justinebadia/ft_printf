/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:41:56 by jbadia            #+#    #+#             */
/*   Updated: 2021/06/23 08:30:02 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_d(long nb, t_flag flag)
{
	int		counter_char;
	char	*str_nb;
	int		nbr;

	counter_char = 0;
	nbr = nb;
	if (flag.dot == 0 && nb == 0)
	{
		counter_char += ft_treat_width(flag.width, 0, 0);
		return (counter_char);
	}
	if (nb < 0 && (flag.dot >= 0 || flag.zero == 1))
	{
		if (flag.zero == 1 && flag.dot == -1)
			ft_putchar('-');
		nb *= -1;
		flag.zero = 1;
		flag.width--;
		counter_char++;
	}
	str_nb = ft_itoa_p(nb);
	counter_char += ft_treat_int_flag(str_nb, nbr, flag);
	free (str_nb);
	return (counter_char);
}

int	ft_treat_int_wprec(char *str_int, int nb, t_flag flag)
{
	int	counter_char;

	counter_char = 0;
	if (nb < 0 && flag.dot >= 0)
		ft_putchar('-');
	if (flag.dot >= 0)
		counter_char += ft_treat_width(flag.dot - 1, ft_strlen(str_int) - 1, 1);
	counter_char += ft_putstr_prec(str_int, ft_strlen(str_int));
	return (counter_char);
}

int	ft_treat_int_flag(char *str_int, int nb, t_flag flag)
{
	int	counter_char;

	counter_char = 0;
	if (flag.minus == 1)
		counter_char += ft_treat_int_wprec(str_int, nb, flag);
	if (flag.dot >= 0 && (size_t)flag.dot < ft_strlen(str_int))
		flag.dot = ft_strlen(str_int);
	if (flag.dot >= 0)
	{
		flag.width -= flag.dot;
		counter_char += ft_treat_width(flag.width, 0, 0);
	}
	else
		counter_char += ft_treat_width(flag.width, ft_strlen(str_int),
				flag.zero);
	if (flag.minus == 0)
		counter_char += ft_treat_int_wprec(str_int, nb, flag);
	return (counter_char);
}
