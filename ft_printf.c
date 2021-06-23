/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:39:27 by jbadia            #+#    #+#             */
/*   Updated: 2021/06/23 08:35:02 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_read_str(const char *str, va_list args, int count_char)
{
	int		i;
	t_flag	flag;
	int		n;

	count_char = 0;
	i = 0;
	while (str[i] && (size_t)i < ft_strlen(str))
	{
		flag = init_flags();
		if (str[i] == '%')
		{
			i = ft_parsing_flags(&flag, str, i + 1, args);
			{
				n = count_char;
				if (ft_type_handle(str[i]))
					count_char += ft_conv((char)flag.conversion, flag, args, n);
				else
					count_char += ft_putchar(str[i]);
			}
		}
		else if (str[i] != '%')
			count_char += ft_putchar(str[i]);
		i++;
	}
	return (count_char);
}

int	ft_printf(const char *str_format, ...)
{
	va_list		args;
	int			counter_char;
	const char	*str;

	str = ft_strdup(str_format);
	counter_char = 0;
	va_start(args, str_format);
	counter_char += ft_read_str(str, args, counter_char);
	va_end(args);
	free((char *)str);
	return (counter_char);
}
