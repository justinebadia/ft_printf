/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:03:09 by jbadia            #+#    #+#             */
/*   Updated: 2021/05/10 15:10:30 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	unsigned int	len_src;
	unsigned int	i;

	len_src = ft_strlen(src);
	i = 0;
	if (dest == 0 || src == 0)
		return (0);
	if (destsize == 0)
		return (len_src);
	while ((src[i] != '\0') && (i < (destsize - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len_src);
}
