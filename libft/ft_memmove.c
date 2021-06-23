/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:01:37 by jbadia            #+#    #+#             */
/*   Updated: 2021/05/12 14:48:33 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*p_dest;
	char	*p_src;

	p_dest = (char *)dest;
	p_src = (char *)src;
	if (dest < src)
	{
		while (len-- > 0)
			*p_dest++ = *p_src++;
	}
	else
	{
		p_dest = p_dest + (len - 1);
		p_src = p_src + (len - 1);
		while (len > 0)
		{
			*p_dest = *p_src;
			p_dest--;
			p_src--;
			len--;
		}
	}
	return (dest);
}
