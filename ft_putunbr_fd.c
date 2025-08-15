/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:53:44 by nicolas           #+#    #+#             */
/*   Updated: 2025/08/15 14:20:28 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_uintlen(unsigned int n)
{
	size_t	size;
	long	number;

	number = (long)n;
	size = 0;
	if (number == 0)
		size++;
	while (number >= 10)
	{
		number /= 10;
		size++;
	}
	if (number == 10)
		size += 2;
	else
		size++;
	return (size);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char	result_str[10];
	long	number;
	int		i;

	number = (long)n;
	i = ft_uintlen(n);
	result_str[i--] = '\0';
	if (number == 0)
		result_str[i] = '0';
	while (number >= 10)
	{
		result_str[i--] = (number % 10) + '0';
		number /= 10;
	}
	if (number == 10)
	{
		result_str[i--] = '1';
		result_str[i] = '0';
	}
	else
		result_str[i] = number + '0';
	ft_putstr_fd(result_str, fd);
}
