/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:42:11 by jbadia            #+#    #+#             */
/*   Updated: 2021/06/22 12:25:08 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_percent (t_flag flag)
{
	int	counter_char;

	counter_char = 0;
	if (flag.minus == 1)
		counter_char += ft_putstr_prec("%", 1);
	counter_char += ft_treat_width(flag.width, 1, flag.zero);
	if (flag.minus == 0)
		counter_char += ft_putstr_prec("%", 1);
	return (counter_char);
}
