/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_utohex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:41:34 by jbadia            #+#    #+#             */
/*   Updated: 2021/06/22 14:11:17 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_convert_utohex (unsigned long long nb_unsigned,
							 int lower, char *str_hexa, int len)
{
	while (nb_unsigned != 0)
	{
		if ((nb_unsigned % 16) < 10)
			str_hexa[len - 1] = (nb_unsigned % 16) + '0';
		else
		{
			if (lower == 0)
				str_hexa[len - 1] = (nb_unsigned % 16) + ('A' - 10);
			if (lower == 1)
				str_hexa[len - 1] = (nb_unsigned % 16) + ('a' - 10);
		}
		nb_unsigned /= 16;
		len--;
	}
	return (str_hexa);
}

char	*ft_put_str_hexa(unsigned long long nb, int lower)
{
	char		*str_hexa;
	long long	nb_unsigned;
	int			len;

	len = 0;
	nb_unsigned = nb;
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	str_hexa = malloc(sizeof(char) * (len + 1));
	if (str_hexa == NULL)
		return (0);
	str_hexa[len] = '\0';
	str_hexa = ft_convert_utohex(nb_unsigned, lower, str_hexa, len);
	return (str_hexa);
}

int	ft_print_hexa(unsigned int u_nb, int lower, t_flag flag)
{
	int		char_counter;
	char	*str_hexa;

	char_counter = 0;
	u_nb = (unsigned int)(4294967295 + 1 + u_nb);
	if (flag.dot == 0 && u_nb == 0)
	{
		char_counter += ft_treat_width(flag.width, 0, 0);
		return (char_counter);
	}
	str_hexa = ft_put_str_hexa((unsigned long long)u_nb, lower);
	char_counter += ft_treat_hex_flag(str_hexa, flag);
	free(str_hexa);
	return (char_counter);
}

int	ft_treat_hex_flag(char *str_hexa, t_flag flag)
{
	int	counter_char;

	counter_char = 0;
	if (flag.dot >= 0 && (size_t)flag.dot < ft_strlen(str_hexa))
		flag.dot = ft_strlen(str_hexa);
	if (flag.minus == 1)
		counter_char += ft_treat_strhexa_wprec(str_hexa, flag);
	if (flag.dot >= 0)
	{
		flag.width -= flag.dot;
		counter_char += ft_treat_width(flag.width, 0, 0);
	}
	else
		counter_char += ft_treat_width(flag.width, ft_strlen(str_hexa),
				flag.zero);
	if (flag.minus == 0)
		counter_char += ft_treat_strhexa_wprec(str_hexa, flag);
	return (counter_char);
}

int	ft_treat_strhexa_wprec(char *str_hexa, t_flag flag)
{
	int	counter_char;

	counter_char = 0;
	if (flag.dot >= 0)
		counter_char += ft_treat_width(flag.dot, ft_strlen(str_hexa), 1);
	counter_char += ft_putstr_prec(str_hexa, ft_strlen(str_hexa));
	return (counter_char);
}
