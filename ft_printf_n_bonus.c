/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:33:45 by jbadia            #+#    #+#             */
/*   Updated: 2021/06/23 08:38:08 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_n(va_list args, int char_counter)
{
	int	*n;

	n = va_arg(args, int *);
	*n = char_counter;
	return (0);
}
