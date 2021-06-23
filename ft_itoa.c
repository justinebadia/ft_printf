/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:38:29 by jbadia            #+#    #+#             */
/*   Updated: 2021/06/23 08:44:24 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_itoa_p(long n)
{
	char	*str;
	long	nb;
	int		len;
	int		is_negative;

	nb = n;
	len = itoa_length(n);
	str = NULL;
	is_negative = 0;
	str = pre_itoa(str, nb, len, is_negative);
	if (str == NULL)
		return (NULL);
	return (str);
}

int	itoa_length(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*pre_itoa(char	*str, long nb, int len, int is_negative)
{
	is_negative = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (nb == 0)
		str[0] = '0';
	if (str == NULL)
		return (NULL);
	if (nb < 0)
	{
		is_negative++;
		nb *= -1;
	}
	str[len] = '\0';
	while (--len != 0)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (is_negative == 1)
		str[0] = '-';
	else
		str[0] = (nb % 10) + '0';
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	long	nb;
	int		len;
	int		is_negative;

	nb = n;
	len = itoa_length(n);
	str = NULL;
	is_negative = 0;
	str = pre_itoa(str, nb, len, is_negative);
	if (str == NULL)
		return (0);
	return (str);
}
