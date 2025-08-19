/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:14:25 by nicolas           #+#    #+#             */
/*   Updated: 2025/08/19 09:46:21 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_uitohex_len(unsigned int n)
{
	size_t	size;

	size = 0;
	while(n > 16)
	{
		n /= 16;
		size++;
	}
	size ++;
	return (size);
}

char	*ft_uitohex(unsigned int n)
{
	char	*hex_chars;
	char	*converted;
	size_t	hex_len;

	hex_chars = "0123456789abcdef";
	hex_len = ft_uitohex_len(n);
	converted = malloc(hex_len * sizeof(char));
	if (!converted)
		return (NULL);
	converted[hex_len--] = '\0';
	while (n > 16)
	{
		converted[hex_len--] = hex_chars[n % 16];
		n /= 16;
	}
	converted[hex_len] = hex_chars[n];
	return (converted);
}
