/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:01:05 by jbadia            #+#    #+#             */
/*   Updated: 2021/05/12 15:26:54 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	count;

	count = 0;
	if (*s == 0)
		return (0);
	if (*s != '\0' && *s != c)
		count++;
	while (*++s != '\0')
		if (*s != c && *(s - 1) == c)
			count++;
	s++;
	return (count);
}

static char const	*ft_skip_c (char const *s, char c)
{
	while (*s != '\0' && *s == c)
		s++;
	return (s);
}

static char const	*ft_go_toc(char const *s, char c)
{
	while (*s != '\0' && *s != c)
		s++;
	return (s);
}

static char	*ft_copyword(char const *s, char c)
{
	char		*str;
	char const	*p;
	int			length;

	p = s;
	length = 0;
	while (*p && *p != c)
	{
		length++,
		p++;
	}
	str = ft_substr(s, 0, length);
	if (str == 0)
		return (NULL);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t		words;
	char		**split;
	size_t		i;	

	words = ft_countwords(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		 s = ft_skip_c (s, c);
		 split[i] = ft_copyword(s, c);
		 s = ft_go_toc(s, c);
		 i++;
	}
	split[i] = NULL;
	return (split);
}
