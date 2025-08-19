/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:34:01 by nicolas           #+#    #+#             */
/*   Updated: 2025/08/19 16:11:42 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_uiptohex_len(uintptr_t n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		size++;
	while(n > 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}

char	*ft_ptrtohex(void *ptr)
{
	char		*hex_chars;
	char		*converted;
	size_t		hex_len;
	uintptr_t	n;

	hex_chars = "0123456789abcdef";
	n = (uintptr_t)ptr;
	hex_len = ft_uiptohex_len(n);
	converted = malloc((hex_len  + 1) * sizeof(char));
	if (!converted)
		return (NULL);
	converted[hex_len--] = '\0';
	if (n == 0)
		converted[hex_len] = '0';
	while (n > 0)
	{
		converted[hex_len--] = hex_chars[n % 16];
		n /= 16;
	}
	return (converted);
}
