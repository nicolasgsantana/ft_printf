/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:07:22 by nde-sant          #+#    #+#             */
/*   Updated: 2025/07/21 16:36:44 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		to_find;
	size_t				i;

	src = s;
	to_find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == to_find)
			return ((unsigned char *)&src[i]);
		i++;
	}
	return (NULL);
}
